<?php

/**
 * handle import of volunteers - test
 */
function valhalla_volunteers_admin() {
  global $language;

  $args = arg();
  if (isset($args[3]) && preg_match('~^[0-9]+$~', $args[3])) {
    $node = node_load($args[3]);
    if ($args[2] == 'start-election') {
      if (empty($args[4])) {

        if (empty($node->field_date[$language->language][0]['value'])) {
          drupal_set_message(t('Valget <em>@title</em> har ikke nogen tilknyttet dato og kan derfor ikke startes.', array('@title' => $node->title)), 'error');
          drupal_goto('admin/valhalla');
        }

        $election_date = date('j/m Y', strtotime($node->field_date[$language->language][0]['value']));
        return '
          <p>' . l('Ja!', implode('/', $args) . '/go', array('attributes' => array('style' => 'font-size:20px;text-decoration:underline;'))) . ' ' . t('jeg vil starte <em>@title</em> den <strong>!date</strong>.', array('@title' => $node->title, '!date' => $election_date)) . '</p>
          <p>Aah, der var vidst lige noget der skulle ' . l('rettes', 'node/edit/' . $args[3], array('attributes' => array('style' => 'text-decoration:underline;'))) . '.</p>
        ';
      }

      $node->field_election_status[$language->language][0]['value'] = 1;
      node_save($node);
      drupal_set_message(t('Valget er nu startet !'));
      drupal_goto('admin/valhalla');
    }
    if ($args[2] == 'stop-election') {
      if (empty($args[4])) {
          return '
          <p>' . l('Ja!', implode('/', $args) . '/stop', array('attributes' => array('style' => 'font-size:20px;text-decoration:underline;'))) . ' ' . t('jeg vil stoppe <em>@title</em>.', array('@title' => $node->title)) . '</p>
          <p>Aah, der var vidst lige noget der skulle ' . l('rettes', 'node/' . $args[3] ."/edit", array('attributes' => array('style' => 'text-decoration:underline;'))) . '.</p>
          ';
      }

      $node->field_election_status[$language->language][0]['value'] = 0;
      node_save($node);
      drupal_set_message(t('Valget er nu stoppet !'));
      drupal_goto('admin/valhalla');
    }
  }

  $out = '
    <ul class="action-links">
      <li><a href="/node/add/election">'.t('Opret nyt valg').'</a></li>
    </ul>
    <div>' . t('Liste over kommende eller ikke skedulerede valg') . '</div>
    ';

  $reset = '
    <div>
    <h3>'.t('Nulstil tilforordnede').'</h3>
    <ul>
    <li><a href="/valghalla/volunteers/action/reset/pos">'.t('Nulstil pladser').'</a></li>
    <li><a href="/valghalla/volunteers/action/reset/rsvp">'.t('Nulstil svar').'</a></li></ul>
    </div>
    ';
  return $out . views_embed_view('valg') . $reset;
}

/**
 * Reset volunteers confirmation form
 *
 * @author Thomas Thune Hansen <tth@bellcom.dk>
 */
function valghalla_volunteers_reset(){
  $type = arg(4);

  $types = array(
    'pos' => t('pladser'),
    'rsvp' => t('svar'),
  );

  $form['operation'] = array(
    '#type' => 'hidden',
    '#value' => $type
  );

  $form['#submit'][] = 'valghalla_volunteers_reset_submit';

  $message = t('Er du sikker på at du ønsker at slette alle tilforordenes ') . $types[$type] . '?';

  return confirm_form($form, 'Nulstil frivillige', 'admin/valhalla/', $message, t('Ja, fortsæt'), t('Annuller'));
}

/**
 *
 * @author Thomas Thune Hansen <tth@bellcom.dk>
 */
function valghalla_volunteers_reset_submit(&$form, &$form_state){
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'volunteers');
  $nids = array_keys(reset($query->execute()));

  // Build operations array, handle 10 volunteer nodes, at the time
  $nid_chunks = array_chunk($nids, 10);
  foreach($nid_chunks as $batch_nids){
    $operations[] = array(
      'valghalla_volunteers_reset_batch', array($form_state['values']['operation'], $batch_nids)
    );
  }

  // Start batch
  batch_set(
    array(
      'title' => t('Nulstil frivillige'),
      'operations' => $operations,
      'finished' => 'valghalla_volunteers_reset_finished_batch',
      'file' => drupal_get_path('module', 'valhalla_volunteers') .'/valhalla_volunteers_admin.inc',
    )
  );
}

/**
 * Batch callback
 *
 * @author Thomas Thune Hansen <tth@bellcom.dk>
 */
function valghalla_volunteers_reset_batch($op, $nids, &$context){
  // Loop over nids in this batch
  foreach($nids as $nid){
    $node = node_load($nid);

    // Reset what the user has chosen $op
    switch($op){
      case 'pos':
          $node->field_polling_station_post = array();
        break;

      case 'rsvp':
          $node->field_rsvp = array();
          $node->field_rsvp_comment = array();
        break;
    }

    node_save($node);
  }
}

/**
 * Batch finished callback
 *
 * @author Thomas Thune Hansen <tth@bellcom.dk>
 */
function valghalla_volunteers_reset_finished_batch($success, $results, $operations){
  if($success){
    drupal_set_message(t('De frivillige er nu nulstillet'));
    drupal_goto('admin/valhalla');
  }
}

function valhalla_volunteers_admin_import_form($form, &$form_state) {

  $form['#attributes'] = array('enctype' => "multipart/form-data");
  $form['import'] = array(
    '#type' => 'fieldset',
    '#title' => t('Importér nye frivillige'),
  );
  $form['import']['upload'] = array(
    '#type' => 'file',
  );
  $form['import']['truncate'] = array(
    '#type' => 'checkbox',
    '#title' => t('Slet alle tilforordnede før de importen.'),
  );
  $form['import']['note'] = array(
    '#type' => 'item',
    '#title' => t('Note'),
    '#description' => '<p>'.t('Hvis du vælger at slette alle tilforordnede før importen, vil al information om disse gå tabt.').'</p>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Importér'),
  );

  return $form;
}

function valhalla_volunteers_admin_import_form_validate($form, &$form_state) {
  $validators = array('file_validate_extensions' => array('csv'));
  $file = file_save_upload('upload', $validators);

  if (FALSE == $file) {
    form_set_error('import][upload', t('Mangler en gyldig csv fil.'));
  } else {
    $form_state['file object'] = $file;
  }
}

function valhalla_volunteers_admin_import_form_submit($form, &$form_state) {
  global $language;

  module_load_include('inc', 'valhalla_volunteers', 'valhalla_volunteers');

  /**
   * handle truncate request
   */
  if ($form_state['values']['truncate'] == 1) {
    $nids = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', 'volunteers', '=')
      ->execute()
      ->fetchAll(PDO::FETCH_COLUMN)
    ;
    node_delete_multiple($nids);
  }

  $import = _valhalla_helter_parse_csv_import($form_state['file object']);

  if ($import) {
    drupal_set_message(t('Impotren oprettede @added og opdaterede @updated tilforordnede.', array('@added' => $import['added'], '@updated' => $import['updated'])));

    if ($import['failed']) {
      $msg = '<p>'.t('Følgende CPR numre er ikke gyldige.').'</p><ul>';
      foreach ($import['failed'] as $cpr => $name) {
        $msg .= '<li>' .  $name . ' ' . $cpr .'</li>';
      }
      $msg .= '</ul>';
      drupal_set_message($msg, 'error');
    }
  }
}



function valhalla_volunteers_admin_start_election_form($form, &$form_state, $xtras) {

  $form['info'] = array(
    '#type' => 'item',
    '#title' => t('Så starter vi.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Importér'),
  );

  return $form;
}

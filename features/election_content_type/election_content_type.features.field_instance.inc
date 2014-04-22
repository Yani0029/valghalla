<?php
/**
 * @file
 * election_content_type.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function election_content_type_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-election-field_polling_stations'
  $field_instances['node-election-field_polling_stations'] = array(
    'bundle' => 'election',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_polling_stations',
    'label' => 'Valgsteder',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Valgsteder');

  return $field_instances;
}

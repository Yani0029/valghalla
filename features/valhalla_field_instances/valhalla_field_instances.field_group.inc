<?php
/**
 * @file
 * valhalla_field_instances.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function valhalla_field_instances_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_adresse|node|polling_station|form';
  $field_group->group_name = 'group_adresse';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'polling_station';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_valgsted';
  $field_group->data = array(
    'label' => 'Adresse',
    'weight' => '22',
    'children' => array(
      0 => 'field_address_city',
      1 => 'field_address_door',
      2 => 'field_address_floor',
      3 => 'field_address_road',
      4 => 'field_address_road_no',
      5 => 'field_address_zipcode',
      6 => 'field_sted',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-adresse field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_adresse|node|polling_station|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_andet|node|polling_station|form';
  $field_group->group_name = 'group_andet';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'polling_station';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_valgsted';
  $field_group->data = array(
    'label' => 'Andet',
    'weight' => '25',
    'children' => array(
      0 => 'field_digital_election_list',
      1 => 'field_venue_skolekode',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-andet field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_andet|node|polling_station|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_deltagere|node|polling_station|form';
  $field_group->group_name = 'group_deltagere';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'polling_station';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_valgsted';
  $field_group->data = array(
    'label' => 'Deltagere',
    'weight' => '21',
    'children' => array(
      0 => 'field_volunteers_pr_party_1',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-deltagere field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_deltagere|node|polling_station|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_kontakter|node|polling_station|form';
  $field_group->group_name = 'group_kontakter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'polling_station';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_valgsted';
  $field_group->data = array(
    'label' => 'Kontaktpersoner',
    'weight' => '24',
    'children' => array(
      0 => 'field_contact',
      1 => 'field_venue_contact',
      2 => 'field_venue_contact_name',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-kontakter field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_kontakter|node|polling_station|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ressourcer|node|polling_station|form';
  $field_group->group_name = 'group_ressourcer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'polling_station';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_valgsted';
  $field_group->data = array(
    'label' => 'Ressourcer',
    'weight' => '23',
    'children' => array(
      0 => 'field_venue_team_members',
      1 => 'field_venue_teams',
      2 => 'field_stemmebokse',
      3 => 'field_stemmeoks_sider',
      4 => 'field_bespisning_1',
      5 => 'field_bespisning_2',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-ressourcer field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_ressourcer|node|polling_station|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_valgsteder|node|polling_station|form';
  $field_group->group_name = 'group_valgsteder';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'polling_station';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_valgsted';
  $field_group->data = array(
    'label' => 'Valgsted',
    'weight' => '20',
    'children' => array(
      0 => 'body',
      1 => 'field_constituency',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_valgsteder|node|polling_station|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_valgsted|node|polling_station|form';
  $field_group->group_name = 'group_valgsted';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'polling_station';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Valgsted',
    'weight' => '1',
    'children' => array(
      0 => 'group_valgsteder',
      1 => 'group_adresse',
      2 => 'group_ressourcer',
      3 => 'group_kontakter',
      4 => 'group_deltagere',
      5 => 'group_andet',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_valgsted|node|polling_station|form'] = $field_group;

  return $export;
}

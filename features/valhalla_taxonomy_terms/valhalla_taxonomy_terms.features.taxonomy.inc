<?php
/**
 * @file
 * valhalla_taxonomy_terms.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function valhalla_taxonomy_terms_taxonomy_default_vocabularies() {
  return array(
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => 'Use tags to group articles on similar topics into categories.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'valgtype' => array(
      'name' => 'Valgtype',
      'machine_name' => 'valgtype',
      'description' => 'Er der tale om et kommunal, folketings eller regionsvalg',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'volonteers_meeting_time' => array(
      'name' => 'Mødetid',
      'machine_name' => 'volonteers_meeting_time',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -9,
    ),
  );
}

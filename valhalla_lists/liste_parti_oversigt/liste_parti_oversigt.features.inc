<?php
/**
 * @file
 * liste_parti_oversigt.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function liste_parti_oversigt_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function liste_parti_oversigt_views_api() {
  return array("version" => "3.0");
}

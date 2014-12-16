<?php
/**
 * @file
 * paragraphs_pack_test.features.inc
 */

/**
 * Implements hook_node_info().
 */
function paragraphs_pack_test_node_info() {
  $items = array(
    'pp_test_landing_page' => array(
      'name' => t('Landing page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

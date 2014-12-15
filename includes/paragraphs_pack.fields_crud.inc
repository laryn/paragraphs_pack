<?php

/**
 * @file
 * Fields CRUD functions.
 *
 */

/**
 * Adds body field to a paragraph bundle.
 *
 * @param string $bundle
 *   A paragraph type machine_name.
 * @param $field_label
 *   A label of the field.
 * @return array
 *   An items field instance.
 */
function paragraphs_pack_add_field_body($bundle, $field_label) {
  $field = paragraphs_pack_get_field_body();

  $instance = _paragraphs_pack_add_field(array(
    'field_name' => $field['field_name'],
    'entity_type' => PP_PARAGRAPH_TYPE,
    'bundle' => $bundle,
    'label' => $field_label,
    'widget' => array('type' => 'text_textarea_with_summary'),
    'settings' => array('display_summary' => TRUE),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => 'text_default',
      ),
      'teaser' => array(
        'label' => 'hidden',
        'type' => 'text_summary_or_trimmed',
      ),
    ),
  ));

  return $instance;
}

/**
 * Get/Create body field.
 *
 * This field can be used only on paragraph entity type.
 *
 * @return array
 *  An array containing field values.
 */
function paragraphs_pack_get_field_body() {
  $field = _paragraphs_pack_get_field(array(
    'field_name' => PP_FIELD_BODY,
    'type' => 'text_with_summary',
    'entity_types' => array(PP_PARAGRAPH_TYPE),
  ));

  return $field;
}

/**
 * Adds items field to a paragraph bundle.
 *
 * @param string $bundle
 *   A paragraph type machine_name.
 * @param $field_label
 *   A label of the field.
 * @return array
 *   An items field instance.
 */
function paragraphs_pack_add_field_items($bundle, $field_label, $target_type = 'node') {
  $field = paragraphs_pack_get_field_items();

  $instance = _paragraphs_pack_add_field(array(
    'field_name' => $field['field_name'],
    'entity_type' => PP_PARAGRAPH_TYPE,
    'bundle' => $bundle,
    'label' => $field_label,
    'widget' => array(
      'type' => 'entityreference_autocomplete',
    ),
    'settings' => array(
      'target_type' => $target_type,
    ),
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'type' => PP_FORMATTER_VIEW_MODE,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'hidden',
        'type' => PP_FORMATTER_VIEW_MODE,
      ),
    ),
  ));

  return $instance;
}

/**
 * Get/Create items field.
 *
 * This field can be used only on paragraph entity type.
 *
 * @param string $target_type
 *   An entity type that should be allowed as items input.
 * @return array
 *   An array containing field values.
 */
function paragraphs_pack_get_field_items() {
  $field = _paragraphs_pack_get_field(array(
    'field_name' => PP_FIELD_ITEMS,
    'type' => 'entityreference',
    'entity_types' => array(PP_PARAGRAPH_TYPE),
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
  ));

  return $field;
}

/**
 * Adds view mode field to a paragraph bundle.
 *
 * @param string $bundle
 *   A paragraph type machine_name.
 * @param $field_label
 *   A label of the field.
 * @param $entity_type
 *   An entity type which view modes are displayed.
 * @return array
 *   An view mode field instance.
 */
function paragraphs_pack_add_field_view_mode($bundle, $field_label, $entity_type = 'node') {
  $field = paragraphs_pack_get_field_view_mode($entity_type);

  $instance = _paragraphs_pack_add_field(array(
    'field_name' => $field['field_name'],
    'entity_type' => PP_PARAGRAPH_TYPE,
    'bundle' => $bundle,
    'label' => $field_label,
    'required' => TRUE,
    'display' => array(),
  ));

  return $instance;
}

/**
 * Get/Create view mode field.
 *
 * This field can be used only on paragraph entity type.
 *
 * @param $entity_type
 *   An entity type which view modes are displayed.
 * @return array
 *  An array containing field values.
 */
function paragraphs_pack_get_field_view_mode($entity_type = 'node') {
  $field = _paragraphs_pack_get_field(array(
    'field_name' => PP_FIELD_VIEW_MODE,
    'type' => PP_FIELD_TYPE_VIEW_MODE,
    'entity_types' => array(PP_PARAGRAPH_TYPE),
    'settings' => array(
      'entity_type' => $entity_type,
    ),
    'cardinality' => 1,
  ));

  return $field;
}

/**
 * Adds/Create field instance of PP_PARAGRAPH_TYPE.
 *
 * Helper function.
 *
 * @param array $instance
 *   An array of instance settings.
 * @return array
 *   An instance.
 */
function _paragraphs_pack_add_field($instance) {
  // Check if the instance exists already.
  $instance_info = field_info_instance(PP_PARAGRAPH_TYPE, $instance['field_name'], $instance['bundle']);
  if (empty($instance_info)) {
    field_create_instance($instance);
  }

  return $instance_info;
}

/**
 * Get/Create field by $field settings.
 *
 * Helper function.
 *
 * @param array $field
 *   An array of field settings.
 * @return array
 *   A field.
 */
function _paragraphs_pack_get_field($field) {
  // Check if the field exists already.
  $field_info = field_info_field($field['field_name']);
  if (empty($field_info)) {
    $field_info = field_create_field($field);
  }

  return $field_info;
}

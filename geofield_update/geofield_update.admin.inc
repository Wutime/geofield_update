<?php

/**
 * @file
 * Provides the Google No CAPTCHA administration settings.
 */

/**
 * Form callback; administrative settings
 */
function geofield_update_admin_settings() {

  $types = array();

  // get all node types
  foreach (node_type_get_types() as $type) {
    // count the number of missing entries per content type
    $count = db_query('SELECT count(*) 
                         FROM {node} 
                        WHERE type = :type
                          AND nid NOT IN (
                                  SELECT entity_id 
                                    FROM {field_data_field_geofield} 
                                   WHERE bundle = :type) ', array(':type' => $type->type))->fetchField();

    $types[$type->type] = $type->name . ' ('.$count.' missing geofield entries)';
  }
  ksort($types);

  $form['geofield_update_general_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
  );

  $form['geofield_update_general_settings']['geofield_update_nodes_per_cron'] = array(
    '#type' => 'textfield',
    '#title' => t('Nodes to process per cron run'),
    '#default_value' => variable_get('geofield_update_nodes_per_cron', GEOFIELD_UPDATE_PROCESS_PER_CRON),
    '#maxlength' => 5,
    '#description' => t('Do not set this value too high.  Typically you only have 1,000 geofield inquiries per day, so set this value as a division of the number of times your cron runs per day (minus how many manual geofield looks up you typically have in a day).'),
    '#required' => TRUE,
  );
  
  $form['geofield_update_general_settings']['geofield_update_content_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types'),
    '#description' => t('Select the content types whose geofield should be updated.  Note, only those content types that actually have a geofield attached to them are applicable to this module.'),
    '#options' => $types,
    '#default_value' => variable_get('geofield_update_content_types', array()),
  );
  
  return system_settings_form($form);
}

/**
 * Validation function for geofield_update_admin_settings().
 *
 * @see geofield_update_admin_settings()
 */
function geofield_update_admin_settings_validate($form, &$form_state) {
  $tabindex = $form_state['values']['geofield_update_nodes_per_cron'];
  if (!is_numeric($tabindex)) {
    form_set_error('geofield_update_nodes_per_cron', t('The nodes to process per cron run must be an integer.'));
  }
}

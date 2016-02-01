<?php

/**
 * @file
 * Defines the Space config menu widget.
 */

$plugin = array(
  'title' => t('Space config menu'),
  'description' => t('Display a menu of space config actions.'),
  'single' => TRUE,
  'category' => t('OA Admin'),
  'edit form' => 'oa_core_space_config_edit_form',
  'render callback' => 'oa_core_space_config_render',
  'defaults' => array(
    'btn_class' => 'btn',
    'icon_class' => 'icon-cog',
    'direction' => '',
  ),
);


/**
 * Render callback for the pane.
 */
function oa_core_space_config_render($subtype, $conf, $args, $context = NULL) {
  if (!module_exists('og_ui')) {
    return FALSE;
  }

  $etid = oa_core_get_space_context();
  $entity_type = 'node';
  $items = og_ui_get_group_admin($entity_type, $etid);

  foreach ($items as &$item) {
    // Re-format the URL.
    $item['href'] = "group/$entity_type/$etid/" . $item['href'];
    // Imitate the menu_get_item() content, so we can pass it to
    // theme_admin_block_content(), so we add the localized_options key.
    $item['localized_options'] = array();
  }

  $btn_class = !empty($conf['btn_class']) ? check_plain($conf['btn_class']) : 'btn';
  $direction = !empty($conf['direction']) ? check_plain($conf['direction']) : '';
  $icon = !empty($conf['icon_class']) ? check_plain($conf['icon_class']) : 'icon-cog';

  $block = new stdClass();
  $block->title = '';
  $output = "<div class='dropdown-toggle $btn_class $direction' data-toggle='dropdown'><i class='$icon'></i></div>";
  $output .= theme('links', array(
    'links' => $items,
    'attributes' => array('class' => array('dropdown-menu')),
  ));
  $block->content = $output;

  return $block;
}

/**
 * Edit form for the panel.
 */
function oa_core_space_config_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['direction'] = array(
    '#type' => 'select',
    '#title' => t('Direction'),
    '#options' => array(
      '' => t('Drop down'),
      'dropup' => t('Drop up'),
    ),
    '#default_value' => (isset($conf['direction'])) ? $conf['direction'] : '',
    '#description' => t('Controls whether menu expands downwards or upwards.  Default is drop down.'),
  );
  $form['icon_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon class'),
    '#description' => t('CSS class name for icon.  Default is icon-cog.'),
    '#default_value' => !empty($conf['icon_class']) ? $conf['icon_class'] : 'icon-cog',
  );
  $form['btn_class'] = array(
    '#type' => 'textfield',
    '#title' => t('Button classes'),
    '#description' => t('CSS classes to add to buttons.  Leave blank for default buttons.'),
    '#default_value' => !empty($conf['btn_class']) ? $conf['btn_class'] : '',
  );
}

/**
 * Submit handler for edit form. Save the custom form fields we added.
 */
function oa_core_space_config_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}


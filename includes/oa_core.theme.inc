<?php
/**
 * @file
 * Code for Theme functions for OpenAtrium spaces
 */

/**
 * Implements hook_theme()
 */
function oa_core_theme() {
  $path = drupal_get_path('module', 'oa_core') . '/templates';
  return array(
    'oa_core_members_widget' => array(
      'template'  => 'oa-core-members-widget',
      'arguments' => array(
        'public' => NULL,
        'links'  => array(),
      ),
      'path' => $path,
    ),
    'oa_core_register_external_user_form' => array(
      'render element' => 'form',
      'template' => 'oa-core-register-external-user',
      'preprocess functions' => array('oa_core_preprocess_oa_core_register_external_user_form'),
      'path' => $path,
    ),
    'oa_core_summary' => array(
      'template'  => 'oa-core-summary',
      'path' => $path,
    ),
    'oa_core_user_spaces' => array(
      'template'  => 'oa-core-user-spaces',
      'path' => $path,
    ),
    'oa_core_node_token' => array(
      'template'  => 'oa-core-node-token',
      'path' => $path,
    ),
    'views_view_fields__oa_user_spaces__full' => array(
      'template'  => 'views-view-fields--oa-user-spaces--full',
      'base hook' => 'views_view_fields',
      'preprocess functions' => array(
        'template_preprocess',
        'template_preprocess_views_view_fields',
      ),
      'arguments' => array('view' => NULL, 'options' => NULL, 'row' => NULL),
      'path' => $path,
    ),
  );
}

function oa_core_preprocess_oa_core_register_external_user_form(&$vars) {
  $form = $vars['form'];
  $vars['name'] = drupal_render($form['account']['name']);
  $vars['mail'] = drupal_render($form['account']['mail']);
  $vars['pass'] = drupal_render($form['account']['pass']);
  $vars['roles'] = drupal_render($form['account']['roles']);
  $vars['notify'] = drupal_render($form['account']['notify']);
}

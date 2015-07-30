<?php

/**
 * @file
 * Defines a widget used to add external users to the site and then to the space and team if necessary.
 */

$plugin = array(
  'title' => t('Add External User'),
  'description' => t('Allows new users to be added to the site and then as members to the space.'),
  'single' => TRUE,
  'category' => t('OA Admin'),
  'render callback' => 'oa_core_add_external_user_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);


/**
 * Render callback for the add external user plugin.
 */
function oa_core_add_external_user_render($subtype, $conf, $args, $context = NULL) {

  if (empty($context->data->nid)
    || !(($nid = oa_core_get_group_from_node($context->data))
      && ($group = node_load(oa_core_get_group_from_node($nid))))
    || !node_access('view', $group)
    || !og_user_access('node', $group->nid, 'add external users')) {
    return;
  }

  ctools_include('modal');
  ctools_modal_add_js();

  // A simple form with a button.
  $form = drupal_get_form('oa_core_add_external_user_button', $context->data);
  $output = drupal_render($form);

  $block = new stdClass();
  $block->title = t('Add External User');
  $block->content = $output;

  return $block;
}

function oa_core_add_external_user_button($form, &$form_state, $group) {

  $form['url'] = array(
    '#type' => 'hidden',
    // The name of the class is the #id of $form['ajax_button'] with a "-url" suffix.
    '#attributes' => array('class' => array('oa-core-add-external-user-button-url')),
    '#value' => url('external-user/nojs/' . $group->nid),
  );

  $form['ajax_button'] = array(
    '#type' => 'button',
    '#value' => t('Add User'),
    '#attributes' => array('class' => array('ctools-use-modal btn-primary')),
    '#id' => 'oa-core-add-external-user-button',
  );

  return $form;
}

function oa_core_register_external_user_modal($js = FALSE, $group) {

  // This is kind of hacky but there really isn't a good way to get the underlying page url.
  if ($group->type == OA_SPACE_TYPE) {
    // If it's an oa_space then we know we came from the members page.
    $url = 'node/' . $group->nid . '/members';
  }
  else if ($group->type == OA_TEAM_TYPE || $group->type == OA_GROUP_TYPE) {
    // If it's an oa_team then we came from the team node.
    $url = 'node/' . $group->nid;
  }

  if ($js) {
    ctools_include('ajax');
    ctools_include('modal');
    ctools_modal_add_js();
    $form_state = array(
      'ajax' => TRUE,
      'title' => t('You are adding an external user.'),
    );
    $output = ctools_modal_form_wrapper('oa_core_register_external_user_form', $form_state);
    if (empty($output) || $form_state['executed']) {
      $output = array();
      $output[] = ctools_modal_command_display('', '<h2>Processing...</h2>');
      $output[] = ctools_modal_command_loading();
      $output[] = ctools_ajax_command_redirect($url);
      unset($_SESSION['register_external_user_page_path']);
    }
    print ajax_render($output);
    drupal_exit();
  }
  else {
    return drupal_get_form('oa_core_add_external_user_ajax_form');
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function oa_core_form_oa_core_register_external_user_form_alter(&$form, &$form_state) {
  // Add our own submit handler.
  $form['#submit'][] = "oa_core_register_external_user_form_submit";
}

/**
 * Submit handler for adding member
 * @param  $form
 * @param  $form_state
 * @return mixed
 */
function oa_core_register_external_user_form_submit($form, &$form_state) {

  if ($account = $form['#user']) {
    $args = menu_get_item();
    list(, $group) = $args['page_arguments'];
    if ($group->type == OA_SPACE_TYPE || $group->type == OA_GROUP_TYPE) {
      // Add the member to the space.
      oa_core_add_member_api('node', $group->nid, $account->uid);
    }
    else if ($group->type == OA_TEAM_TYPE) {
      // Load the space the team belongs to.
      $space_nid = oa_core_get_group_from_node($group);
      // Add the member to the space.
      oa_core_add_member_api('node', $space_nid, $account->uid);
      // Add the member to the team.
      oa_teams_add_member($group, $account->uid);
      // A message gets set for the space. We need to add one for the team as well. Use the 'Display name' so we match
      // the message added when adding a user to a space.
      $wrapper = entity_metadata_wrapper('user', $account);
      $name = $wrapper->field_user_display_name->value();
      drupal_set_message(t('@name has been added to the team @team.', array('@name' => $name, '@team' => $group->title)));
    }
  }
  else {
    drupal_set_message(t('There was an error creating the user. Please contact your group administrator.'), 'error');
  }
}



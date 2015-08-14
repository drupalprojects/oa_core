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
    || !og_user_access('node', $group->nid, 'add external user')) {
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

/**
 * This is what the widget will render. It's just a button that triggers a modal that contains the modified user
 * registration form to add a new user.
 *
 * @param $form
 * @param $form_state
 * @param $group
 * @return mixed
 */
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

/**
 * This is the page callback for "external-user/%ctools_js/%node".
 *
 * @param bool|FALSE $js
 * @param $group
 * @return array|mixed
 */
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
    // Build the form for the modal.
    $output = ctools_modal_form_wrapper('oa_core_register_external_user_form', $form_state);
    // If we don't find the form or it has already been submitted.
    if (empty($output) || $form_state['executed']) {
      $output = array();
      // Give the user something so they know the modal will close and the page will reload.
      // @todo: This would be better if we just added a loader.
      $output[] = ctools_modal_command_display('', '<h2>Processing...</h2>');
      $output[] = ctools_modal_command_loading();
      $output[] = ctools_ajax_command_redirect($url);
    }
    // Render the output and exit.
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
  // Add another submit handler to add the user to the space, team, or group.
  $form['#submit'][] = "oa_core_register_external_user_form_submit";
}

/**
 * Submit handler for adding member.
 *
 * @param  $form
 * @param  $form_state
 * @return mixed
 */
function oa_core_register_external_user_form_submit($form, &$form_state) {

  if ($account = $form['#user']) {
    $args = menu_get_item();
    // Get the group page the widget is being triggered on.
    list(, $group) = $args['page_arguments'];
    // This is an oa_space or oa_group type.
    if ($group->type == OA_SPACE_TYPE || $group->type == OA_GROUP_TYPE) {
      // Add the member to the space.
      oa_core_add_member_api('node', $group->nid, $account->uid);
    }
    // This is an oa_team type.
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
      // Get the 'Display Name' instead of using the actual name.
      $name = $wrapper->field_user_display_name->value();
      drupal_set_message(t('@name has been added to the team @team.', array('@name' => $name, '@team' => $group->title)));
    }
  }
  else {
    // Something went wrong with creating the user.
    drupal_set_message(t('There was an error creating the user. Please contact your group administrator.'), 'error');
  }
}



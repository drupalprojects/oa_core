<?php
/**
 * @file
 * oa_groups.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_groups_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer panelizer node oa_group breadcrumbs.
  $permissions['administer panelizer node oa_group breadcrumbs'] = array(
    'name' => 'administer panelizer node oa_group breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_group content.
  $permissions['administer panelizer node oa_group content'] = array(
    'name' => 'administer panelizer node oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_group context.
  $permissions['administer panelizer node oa_group context'] = array(
    'name' => 'administer panelizer node oa_group context',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_group defaults.
  $permissions['administer panelizer node oa_group defaults'] = array(
    'name' => 'administer panelizer node oa_group defaults',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_group layout.
  $permissions['administer panelizer node oa_group layout'] = array(
    'name' => 'administer panelizer node oa_group layout',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_group overview.
  $permissions['administer panelizer node oa_group overview'] = array(
    'name' => 'administer panelizer node oa_group overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_group settings.
  $permissions['administer panelizer node oa_group settings'] = array(
    'name' => 'administer panelizer node oa_group settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: create oa_group content.
  $permissions['create oa_group content'] = array(
    'name' => 'create oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any oa_group content.
  $permissions['delete any oa_group content'] = array(
    'name' => 'delete any oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own oa_group content.
  $permissions['delete own oa_group content'] = array(
    'name' => 'delete own oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any oa_group content.
  $permissions['edit any oa_group content'] = array(
    'name' => 'edit any oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own oa_group content.
  $permissions['edit own oa_group content'] = array(
    'name' => 'edit own oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: trash any oa_group content.
  $permissions['trash any oa_group content'] = array(
    'name' => 'trash any oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: trash own oa_group content.
  $permissions['trash own oa_group content'] = array(
    'name' => 'trash own oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash any oa_group content.
  $permissions['untrash any oa_group content'] = array(
    'name' => 'untrash any oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash own oa_group content.
  $permissions['untrash own oa_group content'] = array(
    'name' => 'untrash own oa_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  return $permissions;
}

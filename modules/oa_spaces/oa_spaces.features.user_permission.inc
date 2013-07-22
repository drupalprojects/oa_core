<?php
/**
 * @file
 * oa_spaces.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function oa_spaces_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer panelizer node oa_space breadcrumbs.
  $permissions['administer panelizer node oa_space breadcrumbs'] = array(
    'name' => 'administer panelizer node oa_space breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_space content.
  $permissions['administer panelizer node oa_space content'] = array(
    'name' => 'administer panelizer node oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_space context.
  $permissions['administer panelizer node oa_space context'] = array(
    'name' => 'administer panelizer node oa_space context',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_space defaults.
  $permissions['administer panelizer node oa_space defaults'] = array(
    'name' => 'administer panelizer node oa_space defaults',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_space layout.
  $permissions['administer panelizer node oa_space layout'] = array(
    'name' => 'administer panelizer node oa_space layout',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_space overview.
  $permissions['administer panelizer node oa_space overview'] = array(
    'name' => 'administer panelizer node oa_space overview',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: administer panelizer node oa_space settings.
  $permissions['administer panelizer node oa_space settings'] = array(
    'name' => 'administer panelizer node oa_space settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: create oa_space content.
  $permissions['create oa_space content'] = array(
    'name' => 'create oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any oa_space content.
  $permissions['delete any oa_space content'] = array(
    'name' => 'delete any oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own oa_space content.
  $permissions['delete own oa_space content'] = array(
    'name' => 'delete own oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any oa_space content.
  $permissions['edit any oa_space content'] = array(
    'name' => 'edit any oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own oa_space content.
  $permissions['edit own oa_space content'] = array(
    'name' => 'edit own oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: trash any oa_space content.
  $permissions['trash any oa_space content'] = array(
    'name' => 'trash any oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: trash own oa_space content.
  $permissions['trash own oa_space content'] = array(
    'name' => 'trash own oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash any oa_space content.
  $permissions['untrash any oa_space content'] = array(
    'name' => 'untrash any oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  // Exported permission: untrash own oa_space content.
  $permissions['untrash own oa_space content'] = array(
    'name' => 'untrash own oa_space content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'trash_flag',
  );

  return $permissions;
}

<?php
/**
 * @file
 * Renders the user register form when users are being added via the widget.
 */
$form = $variables['form'];
?>
<?php hide($form['account']); ?>
<?php print $variables['name']; ?>
<?php print $variables['mail']; ?>
<?php print $variables['pass']; ?>
<?php print $variables['roles']; ?>
<?php print $variables['notify']; ?>
<?php print drupal_render_children($form); ?>
<?php
/**
 * @file
 * Template for oa_members_toolbar pane.
 */
?>
<ul class="oa-members-toolbar oa_toolbar">
  <li class='dropdown btn-group'>
    <a class='dropdown-toggle href="<?php print $member_url; ?>" <?php print $btn_class; ?> <?php print $direction; ?>' data-toggle='dropdown' href="#" title="<?php print $title?>">
      <i class="<?php print $icon; ?>"></i><span class="element-invisible"><?php print $title;?></span>
    </a>
    <ul class="dropdown-menu" role="menu">
      <li class="dropdown-column">
        <div class="item-list">
          <h3><?php print $space_title; ?></h3>
          <?php print $links; ?>
          <?php if (!empty($admins)): ?>
            <h4><?php print t('Admins'); ?></h4>
            <?php print $admins; ?>
          <?php endif; ?>
          <h4><?php print t('Members'); ?></h4>
          <?php if (!empty($members)): ?>
            <?php print $members; ?>
          <?php endif; ?>
        </div>
      </li>
    </ul>
  </li>
</ul>

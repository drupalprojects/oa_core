<div class="oa-users-submitted align-<?php print $align;?>">
  <?php if ($align == 'left'):?>
    <div class="user-badge">
      <?php if (!empty($picture)):?>
        <?php print $picture; ?>
      <?endif; ?>
      <?php if (!empty($userlink)):?>
        <span><?php print $userlink; ?></span>
      <?endif; ?>
    </div>
  <?endif; ?>
  <div class="oa-description">
    <?php if (!empty($label)):?>
      <?php print $label; ?>
    <?endif; ?>
    <?php if (!empty($date)):?>
      <?php print $date; ?>
    <?endif; ?>
    <?php if (($align == 'right') && (!empty($bylabel))):?>
      <?php print $bylabel; ?>
    <?endif; ?>
  </div>
  <?php if ($align == 'right'):?>
    <div class="user-badge">
      <?php if (!empty($userlink)):?>
        <span><?php print $userlink; ?></span>
      <?endif; ?>
      <?php if (!empty($picture)):?>
        <?php print $picture; ?>
      <?endif; ?>
    </div>
  <?endif; ?>
</div>

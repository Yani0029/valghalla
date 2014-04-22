<?php if($posts_to_fill): ?>
<div id="volunteer-station-list">
<?php foreach($posts_to_fill as $i => $post): ?>

  <dl class="clearfix" id="volunteer-station-list-item-<?php print $i ?>">
    <dt class="label-<?php print $post['role_title'] ?>"><?php print $post['role_title'] ?></dt>
    <dd data-post="<?php print $post['role_nid'] . $post['party_tid'] . $i;?>">
      <div class="well well-sm col-xs-6"><?php print (isset($existing[$i]) ? $existing[$i]['data'] : t('Vælg en deltager.')) ?></div>

    <a data-role_nid="<?php print $post['role_nid']; ?>"
       data-party_tid="<?php print $post['party_tid']; ?>"
       data-pollingstation_nid="<?php print $pollingstation_nid; ?>"
      <?php if(isset($existing[$i])): ?> style="display:none;"  <?php endif;?> class="btn btn-default btn-xs js-add-volunteer"><span class="glyphicon glyphicon-plus"></span></a>

    <?php if(isset($existing[$i])): ?>
      <a href="/node/<?php print $existing[$i]['nid'] ?>/edit?destination=<?php print(implode('/', arg())) ?>" class="btn btn-default btn-xs edit"><span class="glyphicon glyphicon-user"></span></a>
      <a data-fcid="<?php print $existing[$i]['fcid'] ?>" class="remove btn btn-default btn-xs js-remove-volunteer" ><span class="glyphicon glyphicon-minus"></span></a>
    <?php endif; ?>
    </dd>
  </dl>
<?php endforeach; ?>
</div>
<?php endif;?>


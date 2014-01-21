<?php if($posts_to_fill): ?>
<div id="volunteer-station-list">
<?php foreach($posts_to_fill as $i => $post): ?>
  

  <dl class="clearfix" id="volunteer-station-list-item-<?php print $i ?>">
    <dt class="label-<?php print $post['title'] ?>"><?php print $post['title'] ?></dt>
    <dd>
      <div><?php print (isset($existing[$i]) ? $existing[$i]['data'] : t('Vælg en tilforordnet')) ?></div>
    <a <?php if(isset($existing[$i])): ?> style="display:none;"  <?php endif; ?>
      href="/ajax/volunteers/station/list/<?php print $party_id ?>/<?php print $station_id ?>/<?php print $i ?>/<?php print $post['nid'] . '-' . $post['party_id'] ?>" class="add<?php print (isset($existing[$i]) ? '' : '') ?>"><i class="fa fa2 fa-plus"></i></a>

    <?php if(isset($existing[$i])): ?>
      <a href="/node/<?php print $existing[$i]['nid'] ?>/edit?destination=<?php print(implode('/', arg())) ?>" class="fa fa2 fa-user edit">Ret</a>
      <a href="/ajax/volunteers/station/remove/<?php print $existing[$i]['fcid'] ?>/<?php print $i ?>" class="fa fa2 fa-minus remove">X</a>
    <?php endif; ?>
    </dd>
  </dl>
<?php endforeach; ?>
</div>
<?php endif;?>

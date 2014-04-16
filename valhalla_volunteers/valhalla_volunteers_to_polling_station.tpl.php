<?php if($posts_to_fill): ?>
<div id="volunteer-station-list">
<?php foreach($posts_to_fill as $i => $post): ?>
  
  <dl class="clearfix" id="volunteer-station-list-item-<?php print $i ?>">
    <dt class="label-<?php print $post['title'] ?>"><?php print $post['title'] ?></dt>
    <dd <?php if(isset($existing[$i])): ?>
        data-nid="<?php print $existing[$i]['nid'] ?>" 
        data-fc_id="<?php print $existing[$i]['fcid'] ?>"
        <?php endif; ?>
        <?php if(isset($existing[$i])): ?> class="assigned"  <?php endif; ?>>
      <div class="volunteer-item col-xs-6"><?php print (isset($existing[$i]) ? $existing[$i]['data'] : t('Vælg en tilforordnet')) ?></div>
      <a href="add/<?php print $party_id ?>/<?php print $station_id ?>/<?php print $i ?>/<?php print $post['nid'] ?>/<?php print $post['party_id'] ?>" class="volunteer-action add<?php print (isset($existing[$i]) ? '' : '') ?>"><span class="glyphicon glyphicon-plus"></span></a>

      <a href="" target="_blank" class="volunteer-action edit"><span class="glyphicon glyphicon-user"></span></a>
      <a href="" class="volunteer-action remove"><span class="glyphicon glyphicon-minus"></span></a>
      <div class="btn btn-sm spinner-loading spinner-sm"></div>
    </dd>
  </dl>
<?php endforeach; ?>
</div>
<?php endif;?>

<div class="modal fade">
  <div class="modal-dialog modal-lg">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
        <h4 class="modal-title">Vælg tilforordnet</h4>
      </div>
      <div class="modal-body">
        <p></p>
        <div class="spinner-loading"></div>
        <table class="volunteers-list table">
          <thead>
            <tr>
              <th>Parti</th>
              <th>Navn</th>
              <th>Vælg</th>
            </tr>
          </thead> 
        </table>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
        <button type="button" class="btn btn-primary">Save changes</button>
      </div>
    </div><!-- /.modal-content -->
  </div><!-- /.modal-dialog -->
</div><!-- /.modal -->

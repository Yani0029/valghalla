var volunteer_info = volunteer_info || {};
(function ($) {
  Drupal.behaviors.valghalla_volunteers = {
    attach: function (context, settings) {

      $('.js-add-volunteer').on('click', function(){
        var $parent = $(this).parent();
        var $el = $(this);

        volunteer_info.post_id = $parent.attr('data-post');
        volunteer_info.pollingstation_nid = $el.attr('data-pollingstation_nid');
        volunteer_info.role_nid = $el.attr('data-role_nid');
        volunteer_info.party_tid = $el.attr('data-party_tid');
        $('.modal').modal();
      });

      $('.js-remove-volunteer').live('click', function(){
        var fcid = $(this).attr('data-fcid');
        $parent = $(this).parent();
        $el = $parent.find('.volunteer');

        $parent.find('.edit').remove();
        $parent.find('.js-remove-volunteer').hide();

        $el.text('...');

        $.post('/ajax/volunteers/station/remove', {'fcid': fcid}, function(data){
          if(data.success){
            $el.text('Vælg en deltager.');
            $parent.find('.js-add-volunteer').show();
            Drupal.behaviors.valghalla_volunteers.populateTable();
          }
        });
      });

      // Select volunteer from modal
      $('.js-select-volunteer').live('click', function(event){
        $('.modal').modal('hide');
        $el = $('[data-post="'+volunteer_info.post_id+'"]');

        $el.find('.js-add-volunteer').remove();
        $el.find('div').text('...');

        volunteer_info.volunteer_nid = $(this).attr('data-volunteer_nid');

        $.post('/ajax/volunteers/station/add', volunteer_info, function(data){
          $el.find('div').html(data.html);
          $el.append('<a href="/node/'+volunteer_info.volunteer_nid+'/edit?destination=volunteers/station/'+volunteer_info.pollingstation_nid+'" class="btn btn-default btn-xs edit"><span class="glyphicon glyphicon-user"></span></a>');

          $el.append('<a data-fcid="'+data.fcid+'" class="remove btn btn-default btn-xs js-remove-volunteer"><span class="glyphicon glyphicon-minus"></span></a>');
        });

        setTimeout(function(){
          Drupal.behaviors.valghalla_volunteers.populateTable();
        }, 500);

      });

      Drupal.behaviors.valghalla_volunteers.populateTable();

    },
    populateTable: function(){
        oTable = $('.volunteers-list').dataTable();
        oTable.fnClearTable();

        $.get('/ajax/volunteers/station/getvolunteers', function(data){
          for (var key in data){
            oTable.fnAddData([ data[key].volunteer_party, data[key].volunteer_name, '<a class="js-select-volunteer" data-volunteer_nid="' + data[key].volunteer_nid + '"><span class="btn btn-xs btn-success">Vælg</span></a>']);
          }
          $('.modal .spinner-loading').remove();
        });
    },
    unsetVolunteer: function(nid){
      var data = Drupal.settings.valghalla_volunteers.volunteers;
      for (var key in data){
        if(data[key].volunteer_nid === nid){
          Drupal.settings.valghalla_volunteers.volunteers.splice(key, 1);
        }
      }
    }
  };
})(jQuery);


/**
jQuery(function(){

  var $dialog = jQuery("div#dialog");
  jQuery("#volunteer-station-list dd a").live('click', function(event) {
    event.preventDefault();

    jQuery('body').append('<div id="loading-gif"></div>');
    if (jQuery(this).hasClass('remove')) {
      var element = this;
      jQuery.post(this.href, function(data) {
        jQuery('#volunteer-station-list-item-' + data.id + ' dd div').html(data.html);
        jQuery('#volunteer-station-list-extra-' + data.id).remove();

        setTimeout(function(){
          if(jQuery('[id*=volunteer-station-list-extra]').length == 0){
            jQuery('.volunteer-station-list-extra-wrapper').remove();
          }
        }, 300);

        jQuery(element).remove();
        if(typeof data.action !== undefined && data.action === "remove"){
          jQuery('#volunteer-station-list-item-' + data.id + ' dd a.add').show();
        }
        jQuery('#loading-gif').remove();
      });
    }
    else if (jQuery(this).hasClass('add')) {
      if (jQuery("#dialog").length == 0) {
        $dialog = jQuery('<div id="dialog"></div>');
      }

      $dialog.load(this.href, function() {
        $dialog.dialog({title:"Vælg en tilforordnet", draggable:false, width: '850px'});
        jQuery('#loading-gif').remove();
      });
    }
    else if (jQuery(this).hasClass('edit')) {
      jQuery('#loading-gif').remove();
      window.location.href = this.href;
    }
  });

  // handle dialog ajax
  jQuery(".ui-dialog-content .views-field-nid a").live("click", function(event) {
    event.preventDefault();

    jQuery('body').append('<div id="loading-gif"></div>');
    jQuery.post(this.href, function(data) {
      if (data.status) {
        jQuery('#volunteer-station-list-item-' + data.id + ' dd div').html(data.html);
        jQuery('#volunteer-station-list-item-' + data.id + ' dd a.remove').remove();
        jQuery('#volunteer-station-list-item-' + data.id + ' dd').append('<a href="/node/' + data.nid + '/edit?destination=' + valhalla_destination_path +'" class="edit btn btn-default btn-xs edit"><span class="glyphicon glyphicon-user"></span></a>');
        jQuery('#volunteer-station-list-item-' + data.id + ' dd').append('<a href="/ajax/volunteers/station/remove/' + data.nid + '/' + data.id + '" class="remove  btn btn-default btn-xs"><span class="glyphicon glyphicon-minus"></a>');

        if(typeof data.action !== undefined && data.action === "add"){
          jQuery('#volunteer-station-list-item-' + data.id + ' dd a.add').hide();
        }
      }
      jQuery('#loading-gif').remove();
    }, "json");
    $dialog.dialog("close");
  });

  // handle dialog ajax pagination
  jQuery('#dialog .pager a').live('click', function(event) {
    event.preventDefault();
    jQuery('#dialog').load(this.href);
  });

  // handle dialog ajax filters
  jQuery('#dialog .view-volunteers form').live('submit', function(event) {
    event.preventDefault();
    var loc = this.action.replace('available-volunteers', 'ajax/volunteers/station/list');
    jQuery('#dialog').append('<div id="loading-gif"></div>');
    jQuery('#dialog').load(loc, jQuery(this).serialize());
  });

  jQuery('.volunteer').hover(function(){
      jQuery(this).find('.rsvp-message').show();
    },
    function(){
      jQuery(this).find('.rsvp-message').hide();
  });
});
*/

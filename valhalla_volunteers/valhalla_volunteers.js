/*
 * @copyright bellcom open source aps
 * @author ulrik nielsen <un@bellcom.dk>
 */

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

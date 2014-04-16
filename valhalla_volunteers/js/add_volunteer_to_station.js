(function($){
  Drupal.behaviors.valghalla_volunteers = {
    attach: function (context, settings) {

      var params = '';


      $('.add').live('click', function(event){
        event.preventDefault();
        $('.modal').modal();
        params = $(this).attr('href').split('/');
      });

      $('.remove').live('click', function(event){
        event.preventDefault();

        $parent = $(this).parent();
        var fc_id = $parent.attr('data-fc_id');
        $parent.addClass('loading');    
        $.post('/ajax/volunteers/station/remove/'+fc_id, function(data){
          if(data.status){
            $parent.find('.volunteer-item').html(data.html);    
            $parent.removeClass('assigned');    
            $parent.removeClass('loading');    
          }
        });
      });

      $('.edit').live('click', function(event){
        $parent = $(this).parent();
        var nid = $parent.attr('data-nid');

        $(this).attr('href', '/node/'+nid+'/edit');
      });

      $('.js-add-volunteer').live('click', function(event){
        event.preventDefault();
        var volunteer = $(this).attr('href').split('/');
        $('.modal').modal('hide');
        $('#volunteer-station-list-item-'+params[3]+' .volunteer-item').text('Tilføjer..');
        $('#volunteer-station-list-item-' +params[3] + ' dd').addClass('loading');

        var senddata = {
          'volunteer' : volunteer[1],
          'role' : params[4],
          'party' : params[5],
          'station' : params[2],
          'list_id' : params[3],
        }

        $.post('/ajax/volunteers/station/add', senddata, function(data){
          $('#volunteer-station-list-item-' + data.list_id + ' .volunteer-item').html(data.html);
          $('#volunteer-station-list-item-' + data.list_id + ' dd').attr('data-nid', senddata.volunteer);
          $('#volunteer-station-list-item-' + data.list_id + ' dd').attr('data-fc_id', data.fc_id);
          $('#volunteer-station-list-item-' + data.list_id + ' dd').addClass('assigned');
          $('#volunteer-station-list-item-' + data.list_id + ' dd').removeClass('loading');
          Drupal.behaviors.valghalla_volunteers.unsetVolunteer(senddata.volunteer);
          Drupal.behaviors.valghalla_volunteers.populateTable();
        });

      });

      // Load all available volunteers, populate table
      $.get('/volunteers/get', function(data){
        if(typeof settings.valghalla_volunteers === 'undefined'){
          settings.valghalla_volunteers = {};
        }
        settings.valghalla_volunteers.volunteers = data;
        Drupal.behaviors.valghalla_volunteers.populateTable();        
      });
      

    },
    populateTable: function(){
        oTable = $('.volunteers-list').dataTable();
        oTable.fnClearTable();

        var data = Drupal.settings.valghalla_volunteers.volunteers;
        for (var key in data){
          oTable.fnAddData(['',data[key].title, '<a class="js-add-volunteer" href="volunteer/' + data[key].nid + '">Tilføj</a>']);
        }
        $('.modal .spinner-loading').remove();
    },
    unsetVolunteer: function(nid){
      var data = Drupal.settings.valghalla_volunteers.volunteers;
      for (var key in data){
        if(data[key].nid === nid){
          Drupal.settings.valghalla_volunteers.volunteers.splice(key, 1);
        }
      }
    }

  };
})(jQuery);

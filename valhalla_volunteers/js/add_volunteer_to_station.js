(function($){
  Drupal.behaviors.valghalla_volunteers = {
    attach: function (context, settings) {
      $.get('/volunteers/get', function(data){
        if(typeof settings.valghalla_volunteers === 'undefined'){
          settings.valghalla_volunteers = {};
        }
        settings.valghalla_volunteers.volunteers = data;
        
        oTable = $('.volunteers-list').dataTable();

        for (var key in data){
          oTable.fnAddData(['', data[key].title, '<a href"">Tilføj</a>']);
        }


      });
    }
  };
})(jQuery);

jQuery(document).ready(function($){
  $('.js-show-volunteer-mail').click(function(event){
    var id = $(this).attr('id');

    var message = $('.js-volunteer-mail-text').html();
    jQuery.get("/valhalla_mail/ajax/view/"+id+"/"+message, function(data){
      $('.js-volunteer-mail').html(data);
    });
  });
});

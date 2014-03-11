jQuery(function($){
  $(document).ready(function(){
    $('#block-menu-menu-leftmenu .menu a[href^="/' + location.pathname.split("/")[1] + '"]').addClass('active');
    var links = $('#block-menu-menu-leftmenu .menu a'); 
      for(var i = 0; i < links.length; i++){ 
          if(links[i].href == location.href) 
              links[i].parentNode.className = 'submenu_active'; 
      };
    /*$('.content .menu').wrap('<div id="main-menu"></div>');
    $('.left_sidebar #main-menu').wrap('<nav id="navigation"></nav>');*/

   $('#block-menu-menu-leftmenu .submenu_active').parent().css('display','block');

    //responsive drop-down <== main nav
    $("<select />").appendTo("#navigation");
    $("<option />", {
       "selected": "selected",
       "value" : "",
       "text" : "Menu"
    }).appendTo("#navigation select");
    $("#navigation a").each(function() {
     var el = $(this);
     $("<option />", {
       "value"   : el.attr("href"),
       "text"    : el.text()
     }).appendTo("#navigation select");
    });
    
    //remove options with # symbol for value
    $("#navigation option").each(function() {
      var navOption = $(this);
      
      if( navOption.val() == '#' ) {
        navOption.remove();
      }
    });
    
    //open link
    $("#navigation select").change(function() {
      window.location = $(this).find("option:selected").val();
    });

    //uniform
    $(function(){
      $("#navigation select").uniform();
      $("#top-navigation select").uniform();
    });
  
  }); // END doc ready
}); // END function
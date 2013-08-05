/**
 * @file
 * Run!
 */

(function($) {
  Drupal.behaviors.yashare = {
    attach: function (context, settings) {
      if (settings.yashare) {
        for (var blockId in settings.yashare) {
          var $block = $('#' + blockId).not('.yashare-processed');
          if ($block.length > 0) {
            $block.addClass('yashare-processed');
            new Ya.share(settings.yashare[blockId]);
          }
        }
      }
    }
  };
})(jQuery);

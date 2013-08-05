<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_project_url']);
    hide($content['field_portfolio_client']);
    hide($content['field_portfolio_image']);
    hide($content['field_portfolio_category']);
	hide($content['field_project_date']);
	hide($content['field_project_images']);
	
	$field_project_images = field_get_items('node', $node, 'field_project_images');
	
?>
  <div class="row">
    <?php if (!empty($content['field_project_images'][0])): ?>
    <div id="slider" class="flexslider">
      <ul class="slides">
        <?php foreach ($field_project_images as $img): ?>
        <li>
          <?php $img_view = file_create_url($img['uri']); ?>
          <a rel="gallery-node-<?php $node->nid; ?>" class="colorbox init-colorbox-processed cboxElement" title="<?php print $img['title'];?>" href="<?php print $img_view; ?>"> <?php print theme('image_style', array('style_name' => 'blog-preview', 'path' => $img['uri'])); ?> </a></li>
        <?php endforeach; ?>
      </ul>
    </div>
    <?php endif;?>
  </div>
  
  <div class="row">
    <div class="eight columns"> <?php print render($content);?> </div>
   
  </div>
  

</div>
<br />

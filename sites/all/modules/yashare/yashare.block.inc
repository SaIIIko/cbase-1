<?php

/**
 * @file
 * Yandex.Share block hooks.
 */

/**
 * Implements hook_block_info().
 */
function yashare_block_info() {
  $blocks['yashare'] = array(
    'info' => t('Yandex.Share'),
    'cache' => DRUPAL_NO_CACHE,
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function yashare_block_view($delta = '') {
  $block = array();
  if ($delta == 'yashare') {
    $block['subject'] = t('Yandex.Share');
    $block['content'] = yashare_build('block');
  }
  return $block;
}

<?php

/**
 * @file
 * Yandex.Share helper functions.
 */

/**
 * Returns all services list or default services.
 */
function yashare_get_services($default = FALSE) {
  if ($default) {
    return array(
      'yaru', 'vkontakte', 'twitter',
      'facebook', 'lj', 'moimir',
      'friendfeed', 'odnoklassniki',
    );
  }
  // Untranslatable services.
  return array(
    'blogger' => 'Blogger',
    'digg' => 'Digg',
    'evernote' => 'Evernote',
    'delicious' => 'Delicious',
    'diary' => 'Дневники',
    'facebook' => 'Facebook',
    'friendfeed' => 'FriendFeed',
    'gplus' => 'Google+',
    'juick' => 'Juick',
    'liveinternet' => 'LiveInternet',
    'linkedin' => 'LinkedIn',
    'lj' => 'LiveJournal',
    'moikrug' => 'Мой Круг',
    'moimir' => 'Мой Мир',
    'myspace' => 'MySpace',
    'odnoklassniki' => 'Одноклассники',
    'tutby' => 'Я тут!',
    'twitter' => 'Twitter',
    'vkontakte' => 'VK.com',
    'yaru' => 'Я.Ру',
    'yazakladki' => 'Яндекс.Закладки',
  );
}

/**
 * Returns services list for block.
 */
function yashare_get_block_services() {
  return array_values(array_filter(variable_get('yashare_block_services', yashare_get_services(TRUE))));
}

/**
 * Returns services list for popup.
 */
function yashare_get_popup_services() {
  return array_values(array_filter(variable_get('yashare_popup_services', yashare_get_services(TRUE))));
}

/**
 * Returns supported languages.
 */
function yashare_get_languages() {
  return array(
    'auto' => t("User's language"),
    'be' => t('Belorussian'),
    'en' => t('English'),
    'kk' => t('Kazakh'),
    'ru' => t('Russian'),
    'tt' => t('Tatarian'),
    'uk' => t('Ukrainian'),
  );
}

/**
 * Returns selected language or protected language for API.
 */
function yashare_get_language($protect = FALSE) {
  $lang = variable_get('yashare_l10n', 'auto');
  if (!$protect) {
    return $lang;
  }

  $langs = yashare_get_languages();
  if ($lang == 'auto') {
    global $language;
    $lang = $language->language;
    if (!array_key_exists($lang, $langs)) {
      $lang = 'ru';
    }
  }
  return $lang;
}

<?php

/**
 * Implementation of hook_views_default_views().
 */
function views_in_code_views_default_views() {
  $files = file_scan_directory(drupal_get_path('module', 'views_in_code') . '/exports/', '/.*\.view$/');
  if (isset($files) && !empty($files)) {
    foreach ($files as $key => $value) {
      require $key;
      if (isset($view)) {
        $views[$view->name] = $view;
      }
    }
    return $views;
  }
}
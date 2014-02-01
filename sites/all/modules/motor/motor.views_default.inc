<?php

/**
 * Implements hook_views_default_views().
 */
function deckfifty_views_default_views() {
 
// exported view goes here
$view = new view();
$view->name = 'proximity_on_map_code';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Proximity on map';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Proximity on map';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Proximity: Distance */
$handler->display->display_options['fields']['distance']['id'] = 'distance';
$handler->display->display_options['fields']['distance']['table'] = 'openlayers_proximity';
$handler->display->display_options['fields']['distance']['field'] = 'distance';
$handler->display->display_options['fields']['distance']['label'] = '';
$handler->display->display_options['fields']['distance']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['distance']['hide_empty'] = 1;
$handler->display->display_options['fields']['distance']['set_precision'] = 0;
$handler->display->display_options['fields']['distance']['precision'] = '2';
$handler->display->display_options['fields']['distance']['format_plural'] = TRUE;
$handler->display->display_options['fields']['distance']['location_provider'] = 'circle';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Proximity: Great-circle */
$handler->display->display_options['filters']['circle']['id'] = 'circle';
$handler->display->display_options['filters']['circle']['table'] = 'openlayers_proximity';
$handler->display->display_options['filters']['circle']['field'] = 'circle';
$handler->display->display_options['filters']['circle']['value']['value'] = '1';
$handler->display->display_options['filters']['circle']['value']['node'] = '2';
$handler->display->display_options['filters']['circle']['location_as'] = 'node';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'proximity-on-map-code';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Proxi on map';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'main-menu';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

 
$views[$view->name] = $view;
 
// return views
  return $views;
}

?>

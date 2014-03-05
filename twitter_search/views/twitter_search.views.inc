<?php




/**
  * Implementation of hook_views_plugins().
  */

  function twitter_search_views_plugins() {

    $plugin = array();

    $plugin['query']['twitter_search_plugin_query'] = array(
      'title' => t('Twitter Search Query'),
      'help' => t('Twitter Search query object.'),
      'handler' => 'twitter_search_plugin_query',
    );
    return $plugin;

  }

/**
 * Implementation of hook_views_data().
 */
function twitter_search_views_data() {

  $data = array();

  // Base data - use module name as the table name here
  $data['twitter_search']['table']['group']  = t('Twitter');
  $data['twitter_search']['table']['base'] = array(
    'title' => t('Tweets'),
    'help' => t('Query Twitter.'),
    'query class' => 'twitter_search_plugin_query'
  );


  // Fields
  $data['twitter_search']['text'] = array(
    'title' => t('Text'),
    'help' => t('The text of this Tweet.'),
    'field' => array(
      'handler' => 'twitter_search_handler_field',
    ),
  );
  $data['twitter_search']['username'] = array(
    'title' => t('Username'),
    'help' => t('The username of the person what Tweeted.'),
    'field' => array(
      'handler' => 'twitter_search_handler_field',
    ),
  );

  return $data;

}
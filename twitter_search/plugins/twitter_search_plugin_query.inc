<?php
/**
 * @file
 *   Views query plugin for Twitter Search.
 */

/**
 * Views query plugin for the Twitter Search.
 */

class twitter_search_plugin_query extends views_plugin_query {

  function query($get_count = FALSE) {  }

  /**
   * Override the execute method to retrieve our data
   * and get it into a format ready for views to work with.
   */
  function execute(&$view) {

    // make the API call
    $settings = array(
      'oauth_access_token' => "304303394-XfpPx4EbfvQFUIzPsUqobSwDo1oGZZrSIiVyB8B6",
      'oauth_access_token_secret' => "sIO6PWEwhuB7VbkhwCyHsNKu8T8kUD5mDpD9EgqWwdDtD",
      'consumer_key' => "KklJd7OAigs6I78nAPNiyg",
      'consumer_secret' => "YAucjqx9KbbAkndHXGUcQO2XHVjo3LSc7D9Dlv0Jmj4"
    );

    $url = 'https://api.twitter.com/1.1/search/tweets.json';
    $getfield = '?q=%23' . $this->options['hashtag'];
    //$getfield = '?q=%23drupalcamplondon';
    $requestMethod = 'GET';

    $twitter = new TwitterAPIExchange($settings);
    $response =  $twitter->setGetfield($getfield)
      ->buildOauth($url, $requestMethod)
      ->performRequest();

    $result = drupal_json_decode($response);

    foreach ($result['statuses'] as $tweet) {

      $row = new stdClass;

      $row->text = $tweet['text'];
      $row->username = $tweet['user']['name'];
      $view->result[] = $row;

    }

  }

  /**
   * Plugin config
   */

  function option_definition() {

    // don't forget to call the parent!
    $options = parent::option_definition();

    $options['hashtag'] = array(
      'default' => 'drupalcamplondon',
    );

    return $options;
  }

  function options_form(&$form, &$form_state) {

    // don't forget to call the parent!
    $form = parent:: options_form($form, $form_state);

    $form['hashtag'] = array(
      '#type' => 'textfield',
      '#title' => t('Hashtag to search for'),
      '#default_value' => $this->options['hashtag'],
    );

  }

}
<?php

/**
 * @file
 * Definition of views_handler_filter_equality.
 */

/**
 * Simple filter to handle equal to / not equal to filters
 *
 * @ingroup views_filter_handlers
 */
class views_handler_filter_shop_product extends views_handler_filter_equality {

  // Override the value_form method to use a select list with labels instead
  function value_form(&$form, &$form_state) {

    parent::value_form($form, $form_state);

    $result = db_query('SELECT pid, title FROM {product}');
    $options = array();
    foreach ($result as $record) {
      $options[$record->pid] = $record->title;
    }

    if ($options) {

      $form['value'] = array(
        '#type' => 'select',
        '#title' => t('Choose a Product to filter on:'),
        '#options' => $options,
        '#default_value' => '0',
        '#required' => FALSE,
      );

    }

  }

}

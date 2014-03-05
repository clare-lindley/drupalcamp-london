<?php

/**
 * Implements hook_views_data()
 */

function shop_views_data () {

  /**
   * PRODUCT TABLE
   */

  // Base table: Product
  $data['product']['table']['group'] = t('Shop');

  // Advertise this table as a possible base table
  $data['product']['table']['base'] = array(
    'field' => 'pid',
    'title' => t('Product'), // this is what shows up in 'Show content of type' screen
    'weight' => -10,

  );

  // Expose the product ID.
  $data['product']['pid'] = array(
    'title' => t('Product: Product ID'),
    'help' => t('The unique internal identifier of the product.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_shop_product',
    ),
/*    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),*/
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Expose the product title.
  $data['product']['title'] = array(
    'title' => t('Product: Product Title'),
    'help' => t('Product Title'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
  );


  /**
   * ORDER TABLE
   * (gets to Product Via Order details)
   */

  $data['orders']['table']['group'] = t('Shop');

  $data['orders']['table']['join']['product'] = array(
    'left_table' => 'order_details',
    'left_field' => 'oid',
    'field' => 'oid',
  );

  // oid
  $data['orders']['oid'] = array(
    'title' => t('Orders: Order ID'),
    'help' => t('The order id'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // order_date
  $data['orders']['order_date'] = array(
    'title' => t('Orders: Order Date'),
    'help' => t('The order date'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // status
  $data['orders']['status'] = array(
    'title' => t('Orders: Order Status'),
    'help' => t('The order status'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_shop_status',
      'label' => t('Status'),
      'use equal' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  /**
   * ORDER DETAILS TABLE
   * (Gets to Product via PID)
   * Note - we dont need a left table here because there's no
   * hops between order_detail and product
   */

  $data['order_details']['table']['group'] = t('Shop');

  $data['order_details']['table']['join']['product'] = array(
    'left_field' => 'pid', // primary key on product
    'field' => 'pid', // field foreign key on order_details
  );

  // Order Details Id
  $data['order_details']['did'] = array(
    'title' => t('Order Details ID'),
    'help' => t('The unique internal identifier of the order details.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Order Id
  $data['order_details']['oid'] = array(
    'title' => t('Order Details: Order ID'),
    'help' => t('The order id'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Product Id
  $data['order_details']['pid'] = array(
    'title' => t('Order Details: Product ID'),
    'help' => t('The product id'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Price
  $data['order_details']['price'] = array(
    'title' => t('Order Details: Order Price'),
    'help' => t('The order price'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;

}
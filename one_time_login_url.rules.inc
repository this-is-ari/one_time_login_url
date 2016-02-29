<?php

/**
 * Implements hook_rules_event_info().
 *
 * @ingroup rules
 */
function one_time_login_url_rules_event_info() {
  return array(
    'one_time_login_url_visited' => array(
      'label' => t('One-Time Login Link was visited.'),
      'group' => t('User'),
      'variables' => array(
        'account' => array(
          'type' => 'user',
          'label' => t("The user's account"),
        ),
      ),
    ),
  );
}

/**
 * Implementation of hook_rules_action_info().
 *
 * @ingroup rules
 */
function one_time_login_url_rules_action_info() {
  return array(
    'one_time_login_url_rules_action' => array(
      'label' => t('Generate One Time Login Link.'),
      'parameter' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
        ),
        'destination' => array(
          'type' => 'uri',
          'label' => t('Destination path'),
          'optional' => TRUE,
        ),
        'expire' => array(
          'type' => 'date',
          'label' => t('Expire Date'),
          'optional' => TRUE
        ),
      ),
      'group' => t('User'),
      'provides' => array(
        'one_time_login_url' => array(
          'type' => 'uri',
          'label' => t('One Time Login Link'),
        ),
      ),
    ),
  );
}

/**
 * Implements Rule's Action.
 *
 * @param object $account
 *   User object.
 * @param string $destination
 *   Path to redirect user after success login.
 * @param string $expire
 *   Expiration time. Value could be a number of seconds from now or from the
 *   begining of Unix Epoc; of in a format suitable for strtotime() function.
 *   @see http://php.net/manual/en/function.strtotime.php
 *   Default is '1 hour'.
 *
 * @return array
 *   Returns the one-time login link for given user prepared for later use in
 *   Rule module actions.
 */
function one_time_login_url_rules_action($account, $destination, $expire) {
  return array('one_time_login_url' => one_time_login_url($account, $destination, $expire ? $expire : '+1 week'));
}


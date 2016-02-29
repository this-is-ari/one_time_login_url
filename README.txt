


Installation
------------

Install 'One Time Login URL' as usual.
Drush:
  drush en one_time_login_url -y


Configuration
-------------

Configured out of the box.


Usage
-----

Direct API calls
================

  global $user;

  $account = $user;
    // User account which should one-time login link be generated to.
    // Optional. Default is current user.
  $destination = 'node/add';
    // Drupal path to redirect after login.
    // Optional. Only internal drupal pathes are allowed.
  $expire = '+1 day';
    // Expire date. Could also be number of seconds from NOW or from Unix Epoc begining.
    // Allowed all values supported by strtotime() function.
    // See http://php.net/manual/en/function.strtotime.php
    // Optional. Default is '+1 week'.

  $url = one_time_login_url($account, $destination, $expire);


Drupal UI
=========

1. Open 'People' page (admin/people).
2. Select users from the list.
3. Choose 'Generate one-time login url for selected users' in 'Update options'
4. Press 'Update' button.

Expected result:
You will see a message with a One Time Login link for each selected user.

Note: Destination and Expire date couldn't be set and default values will be used.


Rules Module
============

Module provides an event 'One-Time Login Link was visited.' which will be fired
when One Time Login Link was used. This event provide a user object for later use.

Module also provides an action 'Generate One Time Login Link.' which generates
a One Time Login Link and pass it to the next action as
'[one-time-login-url:value]' token. So this URL could be shown at page,
emailed to user and etc.







<?php
/**
 * @file keypic.admin.inc
 *
 * Function for keypic admin pages.
 */

/**
 * Settings form for KeyPic web service.
 */
function keypic_admin_settings_form($form, &$form_state) {
  $form['keypic_example'] = array(
    '#type' => 'fieldset',
    '#title' => t('Example'),
    '#description' => t('Presolved KeyPic CAPTCHA example, generated with the current settings.'),
  );

  $form['keypic_example']['keypic'] = array(
    '#type' => 'captcha',
    '#captcha_type' => 'keypic/KeyPic',
    '#captcha_admin_mode' => TRUE,
  );

  return system_settings_form($form);
}

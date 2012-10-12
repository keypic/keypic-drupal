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

  $form['keypic_spam_point'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum spam point'),
    '#default_value' => variable_get('keypic_spam_point', 70),
    '#element_validate' => array('keypic_validate_spam_point_element'),
    '#description' => t(
        'Keypic response point which great this value will be considered as spam.'
          . ' Valid value is from 0 to 100.'
          . ' 0…39: Not spam. 40…69: Maybe spam. 70…100: Is spam.'
      ),
  );

  return system_settings_form($form);
}

function keypic_validate_spam_point_element($element, $form_state, $form) {
  $value = $element['#value'];
  if (is_numeric($value)) {
    if ($value <= 0 || $value >= 100) {
      form_error($element, t('Value is range from 0…100'));
    }
  }
  else {
    form_error($element, t('Value must be number.'));
  }
}

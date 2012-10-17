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

  $form['keypic_form_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Keypic Form ID'),
    '#default_value' => variable_get('keypic_form_id', ''),
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

  $form['keypic_widget_format'] = array(
    '#type' => 'radios',
    '#title' => t('Widget format'),
    '#options' => array(
      'image' => t('Image'),
      'iframe' => t('Iframe'),
    ),
    '#default_value' => variable_get('keypic_widget_format', 'image'),
  );

  $form['keypic_widget_size'] = array(
    '#type' => 'select',
    '#title' => t('Widget size'),
    '#options' => array(
      '' => t('Default'),
      '300x250' => '300x250',
      '250x250' => '250x250',
      '240x400' => '240x400',
      '180x150' => '180x150',
      '300x100' => '300x100',
      '720x300' => '720x300',
      '392x72'  => '392x72',
      '468x60'  => '468x60',
      '234x60'  => '234x60',
      '80x15'  => '80x15',
      '88x31'  => '88x31',
      '120x90'  => '120x90',
      '120x60'  => '120x60',
      '120x240'  => '120x240',
      '125x125'  => '125x125',
      '728x90'  => '728x90',
      '120x600'  => '120x600',
      '160x600'  => '160x600',
      '300x600'  => '300x600',
    ),
    '#default_value' => variable_get('keypic_widget_size', ''),
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

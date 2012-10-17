<?php
/**
 * @file keypic.pages.inc
 *
 * Functions for KeyPic pages
 */

/**
 *  Page callback for KeyPic spam reporting page.
 */
function keypic_report_spam_page_callback($form_id, $token) {
  $counter = db_select('keypic_comment', 'kpc');
  $counter->condition('kpc.token', $token);
  $counter->addExpression('COUNT(*)', 'counter');
  $counter = $counter->execute()->fetchColumn();
  if ($counter) {
    module_load_include('php', 'keypic', 'Keypic');
    Keypic::setFormID($form_id);
    Keypic::reportSpam($token);
    drupal_goto('admin/content/comment');
  }
  return drupal_not_found();
}

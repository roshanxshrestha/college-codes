<?php
// Load the XML file
$xml = new DOMDocument();
$xml->load('users.xml');

// Get the user ID from input
$user_id = $_GET['user_id'];

// Find the user element with the matching ID
$user = $xml->getElementsByTagName('user')->item($user_id - 1);

// Extract user details
$user_details = array(
  'id' => $user->getElementsByTagName('id')->item(0)->nodeValue,
  'name' => $user->getElementsByTagName('name')->item(0)->nodeValue,
  'email' => $user->getElementsByTagName('email')->item(0)->nodeValue,
);

// Display user details
echo 'User ID: ' . $user_details['id'] . '<br>';
echo 'Name: ' . $user_details['name'] . '<br>';
echo 'Email: ' . $user_details['email'] . '<br>';
?>

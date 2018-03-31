<?php
$fp = fopen("php://stdin", "r");
$str = fgets($fp);
$str = strtolower($str);

$letters = array_count_values(str_split($str));
unset($letters[" "]);

echo (sizeof($letters) == 26 ? "" : "not ")."pangram";

?>
<?php

$handle = fopen ("php://stdin", "r");
$arr_temp = fgets($handle);
$arr = explode(" ",$arr_temp);
$arr = array_map('intval', $arr);

sort($arr);
echo (array_sum($arr)-$arr[sizeof($arr)-1])." ".(array_sum($arr)-$arr[0]);

?>
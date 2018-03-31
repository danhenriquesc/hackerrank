<?php

$handle = fopen ("php://stdin", "r");
function migratoryBirds($n, $ar) {
    sort($ar);
    $x = array_count_values($ar);
    arsort($x);
    
    foreach($x as $key=>$value) return $key;
}

fscanf($handle, "%i",$n);
$ar_temp = fgets($handle);
$ar = explode(" ",$ar_temp);
$ar = array_map('intval', $ar);
$result = migratoryBirds($n, $ar);
echo $result . "\n";

?>
<?php

$handle = fopen ("php://stdin", "r");
function lonelyinteger($a) {
    $c = array_count_values($a);
    foreach($c as $key=>$value){
        if($value == 1) return $key;
    }
}

fscanf($handle, "%i",$n);
$a_temp = fgets($handle);
$a = explode(" ",$a_temp);
$a = array_map('intval', $a);
$result = lonelyinteger($a);
echo $result . "\n";

?>
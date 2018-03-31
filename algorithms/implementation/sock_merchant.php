<?php

$handle = fopen ("php://stdin", "r");
function sockMerchant($n, $ar) {
    $tot = 0;
    $ar = array_count_values($ar);
    foreach($ar as $key=>$value){
        $tot += floor($value/2);
    }
    return $tot;
}

fscanf($handle, "%i",$n);
$ar_temp = fgets($handle);
$ar = explode(" ",$ar_temp);
$ar = array_map('intval', $ar);
$result = sockMerchant($n, $ar);
echo $result . "\n";

?>
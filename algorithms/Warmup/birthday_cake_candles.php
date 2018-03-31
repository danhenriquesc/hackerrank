<?php

$handle = fopen ("php://stdin", "r");
function birthdayCakeCandles($n, $ar) {
    rsort($ar);
    
    $number = $ar[0];
    $n=0;
    
    $i=0;
    while ($ar[++$n] == $number);
    
    return $n;
}

fscanf($handle, "%i",$n);
$ar_temp = fgets($handle);
$ar = explode(" ",$ar_temp);
$ar = array_map('intval', $ar);
$result = birthdayCakeCandles($n, $ar);
echo $result . "\n";

?>
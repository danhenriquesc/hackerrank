<?php

$handle = fopen ("php://stdin", "r");
function bonAppetit($n, $k, $b, $ar) {
    $mayCharge = (array_sum($ar) - $ar[$k])/2;
    return ($b-$mayCharge) ? ($b-$mayCharge) : "Bon Appetit";
}

fscanf($handle, "%i %i", $n, $k);
$ar_temp = fgets($handle);
$ar = explode(" ",$ar_temp);
$ar = array_map('intval', $ar);
fscanf($handle, "%i",$b);
$result = bonAppetit($n, $k, $b, $ar);
echo $result . "\n";

?>

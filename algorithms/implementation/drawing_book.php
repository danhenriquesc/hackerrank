<?php

$handle = fopen ("php://stdin", "r");
function solve($n, $p){
    $p = floor($p/2);
    $n = floor($n/2);
    return min($p, $n-$p);
}

fscanf($handle,"%d",$n);
fscanf($handle,"%d",$p);
$result = solve($n, $p);
echo $result . "\n";

?>
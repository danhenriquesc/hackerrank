<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%d",$n);
$a_temp = fgets($handle);
$a = explode(" ",$a_temp);
array_walk($a,'intval');

$a = array_count_values($a);
    
$max = -1;
for($i = 1; $i <99; $i++){
    $max = max($max, $a[$i] + $a[$i+1]);
}

echo $max;

?>
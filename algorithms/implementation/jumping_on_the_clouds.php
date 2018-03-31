<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%d",$n);
$c_temp = fgets($handle);
$c = explode(" ",$c_temp);
array_walk($c,'intval');

$i=0;
$jumps = 0;
while($i<$n-1){
    if($c[$i+2] == 0)
        $i+=2;
    else
        $i++;
    
    $jumps++;
}
echo $jumps;
?>
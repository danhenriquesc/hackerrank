<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%d",$n);
$A_temp = fgets($handle);
$A = explode(" ",$A_temp);
array_walk($A,'intval');

$min = 100000000000000000000;
$found = false;

for($i=0;$i<$n;$i++){
    for($j=$i+1;$j<=$n-1;$j++){
        if($A[$i] == $A[$j]){
            $dist = $j-$i;
            if($dist < $min)
                $min = $dist;
            $found = true;
        }
    }
}

if(!$found) echo "-1";
else echo $min;

?>
<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%d %d",$n,$k);
$a_temp = fgets($handle);
$a = explode(" ",$a_temp);
array_walk($a,'intval');

$count = 0;
for($i=0;$i<$n-1;$i++){
    for($j=$i+1;$j<$n;$j++){
        if((($a[$i] + $a[$j]) % $k) == 0) $count++;
    }
}
echo $count;

?>
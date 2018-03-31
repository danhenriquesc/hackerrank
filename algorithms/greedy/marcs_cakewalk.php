<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%d",$n);
$calories_temp = fgets($handle);
$calories = explode(" ",$calories_temp);
array_walk($calories,'intval');
rsort($calories);
$tot = 0;
for($i=0; $i < sizeof($calories); $i++){
    $tot += $calories[$i] * pow(2,$i);
}
echo $tot;
?>
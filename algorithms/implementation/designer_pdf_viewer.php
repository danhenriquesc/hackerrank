<?php

$handle = fopen ("php://stdin","r");
$h_temp = fgets($handle);
$h = explode(" ",$h_temp);
array_walk($h,'intval');
fscanf($handle,"%s",$word);

$let = [];

$j = 0;
for($i = 'a'; $i <= 'z'; $i++){
    $let[$i] = $j++;
}


$f = [];
for($i=0; $i<strlen($word); $i++){
    $f[] = $h[$let[$word[$i]]];
}
rsort($f);

print ($f[0]*strlen($word));

?>
<?php
$handle = fopen("php://stdin", "r");
fscanf($handle,"%d",$n);
$arr_temp = fgets($handle);
$arr = explode(" ",$arr_temp);
array_walk($arr,'intval');
$arr = array_count_values($arr);
for($i=0;$i<=99;$i++){
    echo (trim($arr[$i])!=""?$arr[$i]:"0")." ";
}

?>
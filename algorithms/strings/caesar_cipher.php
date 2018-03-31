<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%d",$n);
fscanf($handle,"%s",$s);
fscanf($handle,"%d",$k);

$chars = array_merge(range('a','z'), range('A','Z'));
$chars_map = [];
for($i = 0; $i < sizeof($chars); $i++){
    $ch = $chars[$i];
    for($j = 0; $j < $k; $j++) $ch++;
    if(strlen($ch) == 2) $ch = $ch[1];
    $chars_map[$chars[$i]] = $ch;
}

for($i = 0; $i < strlen($s); $i++){
    if(in_array($s[$i], $chars)){
        echo $chars_map[$s[$i]];
    }else{
        echo $s[$i];
    }
}

?>
<?php

$handle = fopen ("php://stdin", "r");
function super_reduced_string($s){
    $i = 1;
    while($i < strlen($s)){
        if($s[$i-1] == $s[$i]){
            $s = substr($s, 0, $i-1).substr($s, $i+1);
            $i = 1;
        }else{
            $i++;
        }
    }
    
    if(strlen($s) == 0){
        $s = 'Empty String';
    }
    
    return $s;
}

fscanf($handle, "%s",$s);
$result = super_reduced_string($s);
echo $result . "\n";

?>
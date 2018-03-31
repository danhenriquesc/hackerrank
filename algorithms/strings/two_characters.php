<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%d",$len);
fscanf($handle,"%s",$s);

function has_consecutive_chars($s){
    $i = 1;
    while($i < strlen($s)){
        if($s[$i-1] == $s[$i]){
            return true;
        }else{
            $i++;
        }
    }
    
    return false;
}

$chars = array_values(array_unique(str_split($s)));

$max = 0;
for($i = 0; $i < sizeof($chars); $i++){
    for($j = $i+1; $j < sizeof($chars); $j++){
        $new_str = '';
        for($k = 0; $k < strlen($s); $k++){
            if($s[$k] == $chars[$i] || $s[$k] == $chars[$j]){
                $new_str .= $s[$k];
            }
        }
        
        if(!has_consecutive_chars($new_str)){
            $max = max(strlen($new_str), $max);    
        }
    }   
}

echo $max;

?>
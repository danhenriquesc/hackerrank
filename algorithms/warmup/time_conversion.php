<?php

$handle = fopen ("php://stdin", "r");
function timeConversion($s) {
    $timetype = substr($s, -2);
    $time = substr($s, 0, -2);
    $sep = explode(":", $time);
    
    if($sep[0] == '12'){
        if($timetype == 'PM'){
            $sep[0] = 12;
        }else if($timetype == 'AM'){
            $sep[0] = 0;
        }
    }
    else if($timetype == 'PM'){
        $sep[0] += 12;
        if($sep[0] == 24) $sep[0] = 0;
    }
    
    $sep[0] = str_pad($sep[0], 2, '0', STR_PAD_LEFT);
    
    return implode(":", $sep);
}

fscanf($handle, "%s",$s);
$result = timeConversion($s);
echo $result . "\n";

?>
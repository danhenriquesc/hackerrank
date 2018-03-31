<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%d",$t);
for($a0 = 0; $a0 < $t; $a0++){
    fscanf($handle,"%d",$n);
    
    $i = 1;
    
    for($j=0;$j<$n;$j++){
        if($j%2){
            $i+=1;
        }else{
            $i*=2;
        }
    }
    
    echo $i."\n";
}

?>
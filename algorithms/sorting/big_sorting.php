<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%d",$n);
$unsorted = array();
for($unsorted_i = 0; $unsorted_i < $n; $unsorted_i++){
   fscanf($handle,"%s",$unsorted[]);
}

function cmp($a, $b)
{   
    if(strlen($a) == strlen($b)){
        $i = 0;
        while($i < strlen($a)){
            if($a[$i] != $b[$i]){
                return $a[$i] > $b[$i];
            }
            $i++;
        }
    }else{
        return (strlen($a) > strlen($b));
    }
    
}

usort($unsorted, "cmp");
echo(implode("\n",$unsorted));

?>
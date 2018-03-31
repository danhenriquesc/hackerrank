<?php
$handle = fopen("php://stdin", "r");

fscanf($handle,"%d",$f);
fscanf($handle,"%d",$n);

$p =fgets($handle);
$p = explode(" ", $p);
for($i = 0; $i < $n; $i++){
    if($p[$i] == $f){
        echo $i;
        exit();
    }
}

?>
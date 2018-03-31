<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%d",$n);
for($a0 = 0; $a0 < $n; $a0++){
    fscanf($handle,"%s",$s);
    echo count(array_unique(str_split($s)))."\n";
}


?>

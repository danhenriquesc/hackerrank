<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%s",$s);

$count = 1;
for($i=0;$i<strlen($s);$i++){
    if($s[$i] != strtolower($s[$i])) $count++;
}
echo $count;

?>
<?php

$handle = fopen ("php://stdin","r");
fscanf($handle,"%s",$S);

$count = 0;
for($i=0;$i<strlen($S);$i+=3){
    if(substr($S,$i,1) != "S") $count++;
    if(substr($S,$i+1,1) != "O") $count++;
    if(substr($S,$i+2,1) != "S") $count++;
}
echo $count;

?>
<?php
$__fp = fopen("php://stdin", "r");

fscanf($__fp, "%d", $i);

while($i--){
    fscanf($__fp, "%d", $j);
    $b32 = bindec("11111111111111111111111111111111");
    $r = (int)$j ^ (int)$b32;
    echo $r."\n";
}

?>
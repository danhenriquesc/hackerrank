<?php
$_fp = fopen("php://stdin", "r");

fscanf($_fp, "%d\n", $t);

while($t--){
    fscanf($_fp, "%d\n", $m);
    fscanf($_fp, "%d\n", $n);
    $c_line = trim(fgets($_fp));
    $c = explode(" ", $c_line);
    
    $find = false;
    
    for($i=0; $i < $n; $i++){
        if($find) break;
        for($j=$i+1; $j < $n; $j++){
            if($c[$i]+$c[$j] == $m){
                echo ($i+1)." ".($j+1)."\n";
                $find = true;
                break;
            }
        }    
    }
}

?>
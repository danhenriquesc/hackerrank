<?php
function insertionSort( $ar) {
    for($i = sizeof($ar) - 1; $i > 0; $i--){
        $cur = $ar[$i];
        $j = $i - 1;
        while($cur < $ar[$j]){
            $ar[$j+1] = $ar[$j];
            $j--;
            echo implode(" ", $ar)."\n";
        }
        $ar[$j+1] = $cur;
    }
    echo implode(" ", $ar)."\n";

}
$fp = fopen("php://stdin", "r");
fscanf($fp, "%d", $m);
$ar = array();
$s=fgets($fp);
$ar = explode(" ", $s);
for($i=0;$i < count($ar);$ar[$i++]+=0);
insertionSort($ar);
?>
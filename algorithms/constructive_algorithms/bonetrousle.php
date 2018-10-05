<?php
$_fp = fopen("php://stdin", "r");
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
fscanf($_fp, "%d", $t);
for ($i = 0; $i < $t; $i++) {
    fscanf($_fp, "%d %d %d", $n, $k, $b);

    $arBoxes = [];
    $partialSum = 0;
    for ($j = 1; $j <= $b; $j++){
        $arBoxes[] = $j;
        $partialSum += $j;
    }

    if ($partialSum > $n){
        echo "-1\n";
        continue;
    }

    $last = $b - 1;
    $found = true;
    while ($partialSum < $n){
        if ($last < 0) {
            echo "-1\n";
            $found = false;
            break;
        }
        $current = $arBoxes[$last];
        $dif = $n - $partialSum;
        if ($current + $dif > $k){
            $arBoxes[$last] = $k;
            $partialSum += ($k - $current);
        }
        else{
            $arBoxes[$last] = $current + $dif;
            $partialSum += $dif;
        }
        $last--;
        $k--;
    }
    if ($found){
        echo implode(" ", $arBoxes) . "\n";
    }
}
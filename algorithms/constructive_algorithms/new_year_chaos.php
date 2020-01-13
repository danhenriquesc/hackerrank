<?php

function minimumBribes($q) {

    $count = 0;
    $chaotic = false;
    $line = $q;
    $size = count($line);

    for ($i = $size - 1; $i >= 0; $i--) {
        if ($line[$i] - ($i+1) > 2) {
            echo "Too chaotic\n";
            $chaotic = true;
            break;
        }
        for ($j = $line[$i] - 2 > 0 ? $line[$i] - 2 : 0; $j < $i; $j++) {
            if ($line[$j] > $line[$i]) {
                $count++;
            }
        }
    }

    if (!$chaotic) {
        echo $count."\n";
    }

    return 0;
}

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $t);

for ($t_itr = 0; $t_itr < $t; $t_itr++) {
    fscanf($stdin, "%d\n", $n);

    fscanf($stdin, "%[^\n]", $q_temp);

    $q = array_map('intval', preg_split('/ /', $q_temp, -1, PREG_SPLIT_NO_EMPTY));

    minimumBribes($q);
}

fclose($stdin);


<?php

function bubbleSort ($arr) {
    $swaps = 0;
    $sorted = $arr;
    for ($i = 0, $size = count($sorted) - 1; $i < $size; $i++) {
        for ($j = 0; $j < $size - $i; $j++) {
            $k = $j + 1;
            if ($sorted[$k] < $sorted[$j]) {
                $swaps++;
                list($sorted[$j], $sorted[$k]) = array($sorted[$k], $sorted[$j]);
            }
        }
    }

    return [
        'array' => $sorted,
        'swaps'  => $swaps,
    ];
}

// Prompt array
$stdin = fopen('php://stdin', 'r');
echo 'Enter array: ';
$line = trim(fgets(STDIN));
$arr = explode(' ', $line);

list('array' => $sorted, 'swaps' => $swaps) = bubbleSort($arr);
// Print results
echo sprintf('Origin array: %s', implode(',', $arr)) . PHP_EOL;
echo sprintf('Sorted array: %s', implode(',', $sorted)) . PHP_EOL;
echo sprintf('Number of swaps: %d', $swaps) . PHP_EOL;
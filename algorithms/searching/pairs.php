<?php

function findPairs (array $array, $diff) {
    $originLength = count($array);
    if ($originLength === 0) {
        return false;
    }

    $result = 0;
    foreach ($array as $i => $value) {
        for ($j = $i + 1; $j < $originLength; $j++) {
            if (abs($array[$j] - $value) === $diff) {
                $result++;
            }
        }
    }

    return $result;
}

// Prompt item to search
print('Enter target difference: ');
$diff = trim(fgets(STDIN));

// Prompt array
$stdin = fopen('php://stdin', 'r');
print('Enter array: ');
$line = trim(fgets(STDIN));
$arr = explode(' ', $line);

// Print result
print(findPairs($arr, $diff));
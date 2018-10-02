<?php

function binarySearch (array $array, $item) {
    $len = count($array);
    # empty list
    if ($len === 0) {
        return false;
    }

    $midPosition = (int) round($len / 2) - 1;
    $midItem = $array[$midPosition];
    # found item
    if ($midItem === $item) {
        return true;
    }

    if ($item < $midItem) {
        $subArray = array_slice($array, 0, $midPosition);
    } else {
        $subArray = array_slice($array, $midPosition + 1);
    } 

    return binarySearch($subArray, $item);
}

// Prompt array
$stdin = fopen('php://stdin', 'r');
print('Enter array: ');
$line = trim(fgets(STDIN));
$arr = explode(' ', $line);

// Prompt item to search
print('Enter item to search: ');
$item = trim(fgets(STDIN));

// Print result
print(binarySearch($arr, $item) ? 'Found' : 'Not found');
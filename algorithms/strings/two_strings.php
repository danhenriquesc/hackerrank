<?php

function twoStrings($s1, $s2) {
    $s2length = strlen($s2);

    $result = false;
    for ($i = 0; $i < $s2length; $i++) {

        if (strpos($s1, $s2[$i]) !== false) {
            $result = true;
        }
    }

    if ($result) {
        return "YES";
    } else {
        return "NO";
    }
}

$fptr = fopen(getenv("OUTPUT_PATH"), "w");

$stdin = fopen("php://stdin", "r");

fscanf($stdin, "%d\n", $q);

for ($q_itr = 0; $q_itr < $q; $q_itr++) {
    $s1 = '';
    fscanf($stdin, "%[^\n]", $s1);

    $s2 = '';
    fscanf($stdin, "%[^\n]", $s2);

    $result = twoStrings($s1, $s2);

    fwrite($fptr, $result . "\n");
}

fclose($stdin);
fclose($fptr);
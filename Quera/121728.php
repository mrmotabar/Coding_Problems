<?php

function sayHello(array $words, int $reverseIndex): void
{
    // TODO: Implement
    $words[$reverseIndex] = strrev($words[$reverseIndex]);
    $str = "";
    foreach ($words as $word) {
        $str .= $word . " ";
    }
    $str = substr($str, 0, strlen($str) - 1);
    $str .= "\n";
    echo $str;
}

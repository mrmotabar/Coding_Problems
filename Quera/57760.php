<?php
$date = readline();
$d = (int)substr($date, 8, 2);
$m = (int)substr($date, 5, 2);

$ans = 0;
for ($i = 1; $i < min(7, $m); $i++) {
    $ans += 31;
}
for ($i = 7; $i < min(11, $m); $i++) {
    $ans += 30;
}
$ans += $d;
$ans = 365 - $ans + 1;

print $ans;

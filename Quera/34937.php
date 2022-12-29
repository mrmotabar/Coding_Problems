<?php

$filename = "input.txt";
$file = fopen($filename, "r");
$filesize = filesize($filename);
$filetext = fread($file, $filesize);

$flag = false;
$filetext = trim($filetext);
$ans  = "";
for ($i = 0; $i < strlen($filetext); $i++) {
    if ($filetext[$i] == " ") {
        $flag = true;
        continue;
    } else {
        if ($flag) {
            $ans .= strtoupper($filetext[$i]);
            $flag = false;
        } else {
            $ans .= strtolower($filetext[$i]);
        }
    }
}
print $ans;

fclose($file);

#!/bin/bash

echo "Enter string:"

read -r a

reverse=""

for ((i=${#a}-1; i>=0; i--)); do
    reverse="$reverse${a:$i:1}"
done

echo "ORIGINAL: $a"
echo "REVERSE: $reverse"


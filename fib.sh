#!/bin/bash

read -p "Enter n: " n

a=0
b=1

while [ $a -le $n ]; do
    echo $a
    temp=$((a+b))
    a=$b
    b=$temp
done


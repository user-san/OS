#!/bin/bash

echo "Enter numbers separated by space:"
read -r -a numbers

if [ "${#numbers[@]}" -eq 0 ]; then
    echo "Error: No numbers provided"
    exit 1
fi

echo "Numbers entered: ${numbers[@]}"

max=${numbers[0]}

for num in "${numbers[@]:1}"; do
    if [ "$num" -gt "$max" ]; then
        max=$num
    fi
done

echo "The largest value is: $max"


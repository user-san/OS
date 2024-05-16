#!/bin/bash

echo "Enter str:"

declare -a strings

while true; do
    read -r ip_str

    if [ "$ip_str" == "done" ]; then
        break
    fi

    strings+=("$ip_str")
done

for str in "${strings[@]}"; do
    len=${#str}
    echo "$str : $len"
done


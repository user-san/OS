#!/bin/bash

read -p "Enter the length of the random string: " length

random_string=$(LC_ALL=C tr -dc 'a-zA-Z0-9' < /dev/urandom | head -c $length)

echo "Random string: $random_string"


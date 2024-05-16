#!/bin/bash

read -p "Enter a string: " input_string

converted_string=$(echo "$input_string" | tr '[:upper:][:lower:]' '[:lower:][:upper:]')

echo "Original string: $input_string"
echo "Converted string: $converted_string"


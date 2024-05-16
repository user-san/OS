#!/bin/bash

print_chessboard() {
    local black="\033[40m \033[0m"
    local white="\033[47m \033[0m"

    for ((i=1; i<=8; i++)); do
        for ((j=1; j<=8; j++)); do
            if (((i+j)%2 == 0)); then
                echo -e -n "$white"
            else
                echo -e -n "$black"
            fi
        done
        echo ""
    done
}

print_chessboard


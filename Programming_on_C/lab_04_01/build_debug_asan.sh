#!/bin/bash
find_project_directory() {
    if pwd | grep -q "func_tests/data";then
        project_directory=./../..
    elif pwd | grep -q "func_tests/scripts";then
        project_directory=./../..
    elif pwd | grep -q "func_tests";then
        project_directory=./..
    else
        project_directory=.
    fi
    echo "$project_directory"
}

project_directory=$(find_project_directory)
cd "$project_directory" || exit

clang -std=c99 -Wall -Wvla -Werror -pedantic -Wextra -fsanitize=address -fno-omit-frame-pointer -g -o app.exe ./*.c -lm

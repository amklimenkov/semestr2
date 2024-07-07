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


gcc -Wall -Werror -Wvla -std=c99 -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -g3 -c ./*.c


gcc -o app.exe ./*.o -lm
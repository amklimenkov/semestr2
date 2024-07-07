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

filename=main.c
project_directory=$(find_project_directory)
cd "$project_directory" || exit

if [[ ! -e $filename ]];then
    exit 1
fi

gcc -Wall -Werror -std=c99 -Wpedantic -Wvla -Wextra -Wfloat-conversion -Wfloat-equal -c "$filename"
gcc -o app.exe "${filename%.c}.o" -lm

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

file_name="main.c"

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -g3 -c -o "${file_name%.c}.o" "$file_name"
gcc -o app.exe "${file_name%.c}.o" -lm
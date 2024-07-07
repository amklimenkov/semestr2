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

clang -std=c99 -Wall -Werror -pedantic -Wextra -fsanitize=undefined -fno-omit-frame-pointer -g -o app.exe "$file_name" -lm

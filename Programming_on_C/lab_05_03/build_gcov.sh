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


while IFS= read -r cfile
do
        gcc -Wall -Werror -Wvla -std=c99 -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal --coverage -c "$cfile"
done <<< "$(find ./ -name "*.c")"

gcc --coverage -o app.exe ./*.o -lm

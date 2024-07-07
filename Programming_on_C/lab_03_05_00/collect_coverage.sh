#!/bin/bash

find_project_directory() {
    if pwd | grep -q "func_tests/data";then
        project_directory=./../../
    elif pwd | grep -q "func_tests/scripts";then
        project_directory=./../../
    elif pwd | grep -q "func_tests";then
        project_directory=./../
    else
        project_directory=.
    fi
    echo "$project_directory"
}

project_directory=$(find_project_directory)

cd "$project_directory" || exit
./clean.sh

./build_gcov.sh

./func_tests/scripts/func_tests.sh

gcov ./*.o
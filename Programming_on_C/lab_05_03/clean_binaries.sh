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
rm -f "$project_directory"/func_tests/data/*.bin
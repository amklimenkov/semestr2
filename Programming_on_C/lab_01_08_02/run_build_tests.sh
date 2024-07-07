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

start_script() {
    script_name=$1
    ./clean.sh
    echo Script: "$script_name"
    ./"$script_name"
    ./func_tests/scripts/func_tests.sh
    echo 
}

project_directory=$(find_project_directory)
cd "$project_directory" || exit

start_script "build_release.sh"
start_script "build_debug.sh"
start_script "build_debug_ubsan.sh"
start_script "build_debug_msan.sh"
start_script "build_debug_asan.sh"



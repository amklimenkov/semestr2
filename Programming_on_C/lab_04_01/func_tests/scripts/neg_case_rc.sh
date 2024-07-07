#!/bin/bash
ERR_ARGS=1
ERR_OK=0
ERR_WRONG_ANS=2

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

if [[ ! -e "$1" || ! -e "$1" ]];then
    if [[ "$2" == "-v" || "$2" == "--verbose" ]];then
        echo "Ошибка переданных аргументов"
    fi
    exit $ERR_ARGS
fi

file_stream_in=$1
project_directory=$(find_project_directory)
if [[ ! -e "$project_directory"/app.exe ]];then
    if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
        echo "Ошибка нет исполняемого файла app.exe"
    fi
    exit $ERR_WRONG_ANS
fi
"$project_directory/app.exe" < "$file_stream_in" > /dev/null
rc="$?"
if [[ "$rc" == "100" ]];then
    if [[ "$2" == "-v" || "$2" == "--verbose" ]];then
        echo NEGATIVE TEST "${file_stream_in:10}" passed.
    fi
    exit $ERR_OK
else
    if [[ "$2" == "-v" || "$2" == "--verbose" ]];then
        echo NEGATIVE TEST "${file_stream_in:10}" not passed.
    fi
    exit $ERR_WRONG_ANS
fi
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

find_path_to_bin_file() {
    args_file_string=$1
    bin_path=$(echo "$args_file_string" | tr ' ' '\n' | grep ".*\.bin")
    echo "$bin_path"
}

if [[ ! -e "$1" || ! -e "$1" ]];then
    if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
        echo "Ошибка переданных аргументов"
    fi
    exit $ERR_ARGS
fi

file_stream_in=$1
file_args=$2
project_directory=$(find_project_directory)
cd "$project_directory" || exit
if [[ ! -e "$file_stream_in" || ! -e "$file_args" ]];then
    if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
        echo "Ошибка переданных аргументов"
    fi
    exit $ERR_ARGS
fi

if [[ ! -e "./app.exe" ]];then
    if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
        echo "Ошибка нет исполняемого файла app.exe"
    fi
    exit $ERR_WRONG_ANS
fi

args=$(cat "$file_args")
bin_path=$(find_path_to_bin_file "$args")
if [[ -n "$bin_path" ]]; then
    text_file="${bin_path%.bin}.txt"
    if [[ ! -e "$bin_path" ]];then
        ./app.exe import "$text_file" "$bin_path"
    fi
fi
if [[ -z "$args" ]]; then
        if ! ./app.exe < "$file_stream_in" > /dev/null;then
            if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
                echo NEGATIVE TEST "${file_stream_in}" passed.
            fi
            exit $ERR_OK
        else
            if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
                echo NEGATIVE TEST "${file_stream_in}" not passed.
            fi
            exit $ERR_WRONG_ANS
        fi
else
    if ! echo "$args" | xargs ./app.exe > /dev/null;then
        if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
            echo NEGATIVE TEST "${file_stream_in}" passed.
        fi
        exit $ERR_OK
    else
        if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
            echo NEGATIVE TEST "${file_stream_in}" not passed.
        fi
        exit $ERR_WRONG_ANS
    fi
fi

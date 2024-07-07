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

file_stream_in=$1
file_stream_out_expect=$2
if [[ ! -e "$file_stream_in" || ! -e "$file_stream_in" || ! -e "$file_stream_out_expect" || ! -e "$file_stream_out_expect" ]];then
    if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
        echo "Ошибка переданных аргументов"
    fi
    exit $ERR_ARGS
fi

file_stream_in=$1
project_directory=$(find_project_directory)
file_stream_received_output=$project_directory/pos_out.txt
if [[ ! -e "$project_directory"/app.exe ]];then
    if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
        echo "Ошибка нет исполняемого файла app.exe"
    fi
    exit 1
fi
"$project_directory"/app.exe < "$file_stream_in" > "$file_stream_received_output"

./comparator.sh "$file_stream_received_output" "$file_stream_out_expect"
if ./comparator.sh "$file_stream_received_output" "$file_stream_out_expect";then
    if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
        echo POSITIVE TEST "${file_stream_in:10}" passed.
    fi
    exit $ERR_OK
else
    if [[ "$3" == "-v" || "$3" == "--verbose" ]];then
        echo POSITIVE TEST "${file_stream_in:10}" not passed.
    fi
    exit $ERR_WRONG_ANS
fi


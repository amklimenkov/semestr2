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

file_stream_in=$1
file_stream_out_expect=$2
file_args=$3

if [[ ! -e "$file_stream_in"  || ! -e "$file_stream_out_expect" || ! -e "$file_args" ]];then
    if [[ "$4" == "-v" || "$4" == "--verbose" ]];then
        echo "Ошибка переданных аргументов"
    fi
    exit $ERR_ARGS
fi

project_directory=$(find_project_directory)
cd "$project_directory" || exit
file_stream_received_output="./pos_out.txt"
echo "" > "$file_stream_received_output"
if [[ ! -e $file_stream_received_output ]];then
    touch $file_stream_received_output
fi

if [[ ! -e ./app.exe ]];then
    if [[ "$4" == "-v" || "$4" == "--verbose" ]];then
        echo "Ошибка нет исполняемого файла app.exe"
    fi
    exit 1
fi

args=$(cat "$file_args")
bin_path=$(find_path_to_bin_file "$args")
is_bin_file=0
if [[ -n "$bin_path" ]]; then
    text_file="${bin_path%.bin}.txt"
    ./app.exe import "$text_file" "$bin_path"
    is_bin_file=1
fi

if [[ "$is_bin_file" == "1" ]]; then
    echo "$args" | xargs ./app.exe > "$file_stream_received_output"
    
    if [[ ! -s "$file_stream_received_output" ]];then
        ./app.exe export "$bin_path" "$file_stream_received_output"
    fi   
else
    if [[ -z "$args" ]]; then
        ./app.exe < "$file_stream_in" > "$file_stream_received_output"
    else
        pos_out=$(echo "$args" | tr ' ' '\n' | grep ".*pos_out")
        if [[ -z "$pos_out" ]];then
            echo "$args" | xargs ./app.exe > "$file_stream_received_output"
        else
            echo "$args" | xargs ./app.exe
        fi
    fi
fi

if ./func_tests/scripts/comparator.sh "$file_stream_received_output" "$file_stream_out_expect";then
    if [[ "$4" == "-v" || "$4" == "--verbose" ]];then
        echo POSITIVE TEST "${file_stream_in}" passed.
    fi
    exit $ERR_OK

else
    if [[ "$4" == "-v" || "$4" == "--verbose" ]];then
        echo POSITIVE TEST "${file_stream_in}" not passed.
    fi
    exit $ERR_WRONG_ANS
fi


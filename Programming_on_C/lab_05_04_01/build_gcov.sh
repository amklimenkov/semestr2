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

flag_compile=0
while IFS= read -r cfile
do
    ofile="${cfile%.c}.o"
    hfile="${cfile%.c}.h"
    if [ -f "$ofile" ]; then
        # сравнение дат
        if [ "$ofile" -ot "$cfile" ]; then
            gcc -Wall -Werror -Wvla -std=c99 -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal --coverage -c ./*.c
            flag_compile=1
        fi

        if [ "$hfile" -ot "$cfile" ]; then
            gcc -Wall -Werror -Wvla -std=c99 -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal --coverage -c ./*.c
            flag_compile=1
        fi
    else
        gcc -Wall -Werror -Wvla -std=c99 -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal --coverage -c ./*.c
        flag_compile=1
    fi
done <<< "$(find ./ -name "*.c")"

if [ -f "./app.exe" ];then
    if [ "$flag_compile" == "1" ]; then
        gcc --coverage -o app.exe ./*.o -lm    
    fi
else
    gcc --coverage -o app.exe ./*.o -lm
fi


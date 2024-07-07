#!/bin/bash
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal --coverage -o0 -c -o app.o main.c
gcc --coverage -o app.exe app.o -lm
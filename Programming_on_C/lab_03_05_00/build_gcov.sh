#!/bin/bash
gcc -Wall -Werror -Wvla -std=c99 -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal --coverage -c ./*.c
gcc --coverage -o app.exe ./*.o -lm
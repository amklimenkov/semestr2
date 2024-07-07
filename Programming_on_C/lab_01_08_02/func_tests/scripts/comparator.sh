#!/bin/bash

file1=$1
file2=$2
substring="Result: "

if [[ ! -e $file1 || ! -e $file2 ]]; then
  exit 1
fi

string1=$(cat "$file1")
string2=$(cat "$file2")

if [[ $string1 == *"$substring"* ]]; then
    result1="${string1##*"$substring"}"
fi

if [[ $string2 == *"$substring"* ]]; then
    result2="${string2##*"$substring"}"
fi

if [[ "$result1" == "$result2" ]];then
    exit 0
else
    exit 1
fi
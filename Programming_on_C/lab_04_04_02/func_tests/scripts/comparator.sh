#!/bin/bash

file1=$1
file2=$2

if [[ ! -e $file1 || ! -e $file2 ]]; then
  exit 1
fi

result1=$(cat "$file1")
result2=$(cat "$file2")

if [[ "$result1" == "$result2" ]];then
    exit 0
else
    exit 1
fi
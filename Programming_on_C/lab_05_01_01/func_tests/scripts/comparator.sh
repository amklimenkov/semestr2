#!/bin/bash
ERR_OK=0
ERR_WRONG_ANS=1

file_stream_out_received=$1
file_stream_out_expect=$2

out_received=$(grep -oE "[+-]?[0-9]+([.][0-9]+)?" "$file_stream_out_received")
out_expect=$(grep -oE "[+-]?[0-9]+([.][0-9]+)?" "$file_stream_out_expect")
if [[ "$out_received" == "$out_expect" ]];then
    exit $ERR_OK
else
    exit $ERR_WRONG_ANS
fi

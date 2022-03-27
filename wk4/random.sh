#!/usr/bin/bash
NUM=0

while [[ $NUM -lt $1 ]]
do
	echo "$RANDOM"
	NUM=$(($NUM+1))
done


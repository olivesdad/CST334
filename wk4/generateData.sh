#!/usr/bin/bash

COUNT=10

while [[ $COUNT -lt 1501 ]]
do
	cat ./addresses.txt | ./fifo ${COUNT} | tail -2 | rev | cut -d' ' -f1 | rev | xargs >> data
	COUNT=$(($COUNT+10))
done

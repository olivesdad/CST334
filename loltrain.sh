#!/usr/bin/bash
COUNT=0

while [[ ${COUNT} -lt $1 ]]
do
sl | lolcat
COUNT=$(($COUNT+1))
done
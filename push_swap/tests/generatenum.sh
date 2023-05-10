#!/bin/bash

declare -a nums
while [ ${#nums[@]} -lt 500 ]
do
    num=$((RANDOM%2000-1000))
    if [[ " ${nums[*]} " == *" $num "* ]]; then
        continue
    fi
    nums+=("$num")
done
echo "${nums[*]}"
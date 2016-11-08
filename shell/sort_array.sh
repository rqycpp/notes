#!/bin/bash

# http://stackoverflow.com/questions/9516408/sorting-in-shell-script
# 对数组进行排序

arr=(4 1 2 5 7 3 1 5 8 9 10 6)

# First split the array elements into lines.
for el in "${arr[@]}"
do
    echo "$el"
done

# Then sort the lines:
for el in "${arr[@]}"
do
    echo "$el"
done | sort -n

# Now you can assign that to an array again:
arr2=( $(
    for el in "${arr[@]}"
    do
        echo "$el"
    done | sort -n ))
echo "${arr2[@]}"

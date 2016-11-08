#!/bin/bash

# https://www.hackerrank.com/challenges/bash-tutorials---more-on-conditionals
# 给出三边长度,判断三角形类别:等边三角形,等腰三角形,不等边三角形.

# 这里开始读取时犯了一个错误,即:read ${arr[0]}.找了很久才发现.
read arr[0]
read arr[1]
read arr[2]

arr2=($(
for i in ${arr[@]} ; do
    echo $i
done | sort
))

if [ ${arr2[0]} -eq ${arr2[1]} ] ; then
    if [ ${arr2[1]} -eq ${arr2[2]} ] ; then
        echo "EQUILATERAL"
    else
        echo "ISOSCELES"
    fi

elif [ ${arr[1]} -eq ${arr2[2]} ] ; then
    if [ ${arr[0]} - eq ${arr2[1]} ] ; then
        echo "EQUILATERAL"
    else
        echo "ISOSCELES"
    fi

else
    echo "SCALENE"
fi

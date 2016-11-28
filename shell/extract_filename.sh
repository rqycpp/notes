#!/bin/bash

# 提取文件名及后缀

file_jpg="sample.jpg"
name=${file_jpg%.*}
extension=${file_jpg#*.}
echo File name is : $name
echo Extension is : $extension

file_txt=hack.fun.book.txt
name=${file_txt%.*}
echo File name is : $name
name=${file_txt%%.*} # 贪婪模式
echo File name is : $name

extension=${file_txt#*.}
echo Extension is : $extension
extension=${file_txt##*.} # 贪婪模式
echo Extension is : $extension

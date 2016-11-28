#!/bin/bash

# 我们有一个包含重复字符的字符串，如何才能知道每个字符在字符串中出现的次数，并依照下面
# 的格式输出字符串？
# 输入：ahebhaaa
# 输出：4a1b1e2h

INPUT="ahebhaaa"
OUTPUT=`echo $INPUT | sed 's/[^\n]/&\n/g' | sed '/^$/d' | sort | uniq -c | tr -d ' \n'`
echo $OUTPUT

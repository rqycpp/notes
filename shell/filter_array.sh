#!/bin/bash
# Input Format

# The input format consists of a list of country names, each on a separate line.
# The only characters present in the country names will be upper or lower case characters and hyphens.

# Output Format

# From the given list, remove the names that contain 'a' or 'A' in them. If there
# are no names left after removing these characters, you should display a blank line.

# Sample Input

# Namibia
# Nauru
# Nepal
# Netherlands
# NewZealand
# Nicaragua
# Niger
# Nigeria
# NorthKorea
# Norway
# Sample Output

# Niger

i=0
declare -a arr
while read name
do
    arr[$i]=$name
    ((i+=1))
done
declare -a ans=(${arr[@]/*[Aa]*/})
echo ${ans[@]}


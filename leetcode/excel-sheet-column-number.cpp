// Source : https://leetcode.com/problems/excel-sheet-column-number/
// Author : RQY
// Date   : 2016-07-12
/**********************************************************************************
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28

就是将26进制数，转换为10进制数。
 **********************************************************************************/
 class Solution {
 public:
     int titleToNumber(string s) {
         int ans = 0;
 	    for (size_t i = 0; i < s.length(); ++i) {
 		    ans += (s[s.length() - i - 1] - 'A' + 1) * pow(26.0, i * 1.0);
 	    }
 	    return ans;
     }
 };

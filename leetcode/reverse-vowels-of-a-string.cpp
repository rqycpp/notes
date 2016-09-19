// Source : https://leetcode.com/problems/reverse-vowels-of-a-string/
// Author : RQY
// Date   : 2016-09-18
/**********************************************************************************
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
 **********************************************************************************/
 class Solution {
 public:
     string reverseVowels(string s) {
         for(int i = 0, j = s.length() - 1; i < j; ){
             if(!vowels(s[i])){
                 ++i;
                 continue;
             }
             if(!vowels(s[j])){
                 --j;
                 continue;
             }
             swap(s[i], s[j]);
             ++i, --j;
         }
         return s;
     }
     bool vowels(char c){
         c = tolower(c);
         if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
             return true;
         }
         return false;
     }
 };

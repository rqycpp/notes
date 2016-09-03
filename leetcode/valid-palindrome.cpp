// Source : https://leetcode.com/problems/valid-palindrome/
// Author : RQY
// Date   : 2016-09-03
/**********************************************************************************
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
 **********************************************************************************/
 class Solution {
 public:
     bool isPalindrome(string s) {//两个索引，一前一后的往中间走
         if(s.empty())
             return true;
         int i, j;
         for(int i = 0, j = s.length() - 1; i < j; ++i, --j){
             while(!isalnum(s[i]) && i < j){//跨越无效字符的同时要记得i<j，否则当不含有有效字符的时候，会越界访问
                 ++i;
             }
             while(!isalnum(s[j]) && j > i){//同理
                 --j;
             }
             if(tolower(s[i]) != tolower(s[j])){
                 return false;
             }
         }
         return true;
     }
 };

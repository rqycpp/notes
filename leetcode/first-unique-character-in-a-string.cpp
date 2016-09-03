// Source : https://leetcode.com/problems/first-unique-character-in-a-string/
// Author : RQY
// Date   : 2016-09-01
/**********************************************************************************
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
 **********************************************************************************/
 class Solution {
 public:
     int firstUniqChar(string s) {
         int index = -1;
         int myhash[26];
         memset(myhash, 0, sizeof(myhash));
         for(auto ch : s){
             myhash[ch - 'a'] += 1;
         }
         for(int i = 0; i < s.length(); ++i){
             if(myhash[s[i] - 'a'] == 1){
                 index = i;break;
             }
         }
         return index;
     }
 };

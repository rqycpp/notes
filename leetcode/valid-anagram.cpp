// Source : https://leetcode.com/problems/valid-anagram/
// Author : RQY
// Date   : 2016-09-04
/**********************************************************************************
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 **********************************************************************************/
 class Solution {
 public:
     bool isAnagram(string s, string t) {
         if(s.length() != t.length())
             return false;
         int myhash[26];
         memset(myhash, 0, sizeof(myhash));
         for(auto ch : s){
             myhash[ch - 'a'] += 1;
         }
         int i;
         for(i = 0; i < t.length(); ++i){
             if(myhash[t[i] - 'a'] > 0)
                 myhash[t[i] - 'a'] -= 1;
             else
                 return false;
         }
         return true;
     }
 };

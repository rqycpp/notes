// Source : https://leetcode.com/problems/implement-strstr/
// Author : RQY
// Date   : 2016-09-25
/**********************************************************************************
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 **********************************************************************************/
 class Solution {
 public:
     int strStr(string haystack, string needle) {
         if(haystack.length() == 0 && needle.length() == 0)
             return 0;
         for(int i = 0; i < haystack.length(); ++i){
             if(haystack.length() - i < needle.length())
                 break;
             if(strncmp(haystack.substr(i),  needle, needle.length()))
                 return i;
         }
         return -1;
     }
     
     bool strncmp(string a, string b, size_t len){
         size_t i;
         for(i = 0; i < len && i < a.length() && i < b.length(); ++i){
             if(a[i] != b[i])
                 return false;
         }
         if(i == len)
             return true;
         return false;

     }
 };

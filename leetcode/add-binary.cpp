// Source : https://leetcode.com/problems/add-binary/
// Author : RQY
// Date   : 2016-09-25
/**********************************************************************************
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 **********************************************************************************/
 class Solution {
 public:
     string addBinary(string a, string b) {
         const int base = 2;//进制
         int length = max(a.length(), b.length());
         string ans;
         int c = 0;//进位
         auto ita = a.crbegin();
         auto itb = b.crbegin();
         while(length--){
             int numa = 0, numb = 0;
             if(ita != a.crend()){
                 numa = (*ita++) - '0';
             }
             if(itb != b.crend()){
                 numb = (*itb++) - '0';
             }
             ans.push_back((numa + numb + c) % base + '0');
             c = (numa + numb + c) / base;
         }
         if(c){
             ans.push_back('1');
         }
         reverse(ans.begin(), ans.end());
         return ans;
     }
 };

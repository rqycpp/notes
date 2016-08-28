// Source : https://leetcode.com/problems/first-bad-version/first-bad-version/
// Author : RQY
// Date   : 2016-08-26
/**********************************************************************************
You are a product manager and currently leading a team to develop a new product.
Unfortunately, the latest version of your product fails the quality check.
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad.
Implement a function to find the first bad version. You should minimize the number of calls to the API.
 **********************************************************************************/
 // Forward declaration of isBadVersion API.
 bool isBadVersion(int version);

 class Solution {
 public:
     int firstBadVersion(int n) {//二分查找，找下界
         int l = 1, r = n, mid;
         while(l < r){
             //if(l == r) return l;如果while中l <= r
             mid = l + (r - l) / 2;
             if(isBadVersion(mid)){
                 r = mid;
             }
             else{
                 l = mid + 1;
             }
         }
         return l;
     }
 };

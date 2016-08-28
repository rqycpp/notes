// Source : https://leetcode.com/problems/guess-number-higher-or-lower/
// Author : RQY
// Date   : 2016-08-27
/**********************************************************************************
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
 **********************************************************************************/
 // Forward declaration of guess API.
 // @param num, your guess
 // @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
 int guess(int num);

 //开始把guess()函数理解成对我猜测数字结果的返回，而实际上是对正确答案的结果返回，导致了错误。
 class Solution {
 public:
     int guessNumber(int n) {
         int l = 1, r = n, m;
         while(l <= r){
             m = l + (r - l) / 2;
             if(guess(m) == 0){
                 return m;
             }
             else if(guess(m) < 0){//my number is lower
                 r = m - 1;
             }
             else{//my number is higher
                 l = m + 1;
             }
         }
         return -1;
     }
 };

// Source : https://leetcode.com/problems/palindrome-number/
// Author : RQY
// Date   : 2016-09-02
/**********************************************************************************
9. Palindrome Number  QuestionEditorial Solution  My Submissions
Total Accepted: 143756
Total Submissions: 436687
Difficulty: Easy
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
 **********************************************************************************/
 // 因为reverse integer会有溢出的危险，所以只需要将一个整数的一半逆序即可。
 // eg：123321->123 123->123 and 321
 class Solution {
 public:
     bool isPalindrome(int x) {
         if(x < 0)
             return false;
         if(x && x % 10 == 0)//eg:0, 10
             return false;
         int rev = 0;//有人说这里利用了额外的空间，与题目不符。我觉得题目的限制应该是不使用O(n)空间的意思，而不是连O(1)空间也不能用的意思
         while(x > rev){
             rev = rev * 10 +  x % 10;
             x /= 10;
         }
         return (x == rev || x == rev / 10);//奇数长度，偶数长度。1234321->x == 123, rev == 1234，所以要将rev/10
     }
 };

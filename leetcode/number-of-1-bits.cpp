// Source : https://leetcode.com/problems/number-of-1-bits/
// Author : RQY
// Date   : 2016-07-07
/**********************************************************************************
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

Hint:https://en.wikipedia.org/wiki/Hamming_weight

“码重”在计算机组成原理、数字电路通信与逻辑等课程中均接触过这个概念
 **********************************************************************************/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            n = n & (n - 1);
            ++count;
        }
        return count;
    }
};

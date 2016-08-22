// Source : https://leetcode.com/problems/super-ugly-number/
// Author : RQY
// Date   : 2016-08-22
/**********************************************************************************
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
 **********************************************************************************/
 class Solution {
 public:
 	int nthSuperUglyNumber(int n, vector<int>& primes) {
 		vector<int>num{ 1 };
 		vector<int>index(primes.size(), 0);//开始想用迭代器指向num，后来发现num大小会改变，迭代器会失效，所以直接用索引
 		for (int i = 1; i < n; ++i) {
 			int min_ugly = 0x7fffffff;//开始用了0xfffffff结果最后一组数据过不掉
 			for(int j = 0; j < primes.size(); ++j){
 				min_ugly = min(min_ugly, num[index[j]] * primes[j]);
 			}
 			num.push_back(min_ugly);

 			//更新索引值
 			for (int j = 0; j < primes.size(); ++j) {
 				while (num[index[j]] * primes[j] <= min_ugly)
 					++index[j];
 			}
 		}
 		return num.back();
 	}
 };

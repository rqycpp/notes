// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Author : RQY
// Date   : 2016-09-17
/**********************************************************************************
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions
as you like (ie, buy one and sell one share of the stock multiple times). However,
you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 **********************************************************************************/
 //可多次买入多次卖出，但需要注意，手头只能持有一份股票
 //画图，最大收益就是高度差
 //https://leetcode.com/articles/best-time-buy-and-sell-stock-ii/
 class Solution {
 public:
     int maxProfit(vector<int>& prices) {
         int profit = 0;
         for(int i = 1; i < prices.size(); ++i){
             if(prices[i] > prices[i - 1])
                 profit += prices[i] - prices[i - 1];
         }
         return profit;
     }
 };

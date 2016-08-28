// Source : https://leetcode.com/problems/powx-n/
// Author : RQY
// Date   : 2016-08-27
/**********************************************************************************
Implement pow(x, n).
 **********************************************************************************/
 class Solution {
 public:
     double myPow(double x, int n) {
         if(n >= 0)
             return pow(x,n);
         else{
             //if(n == 0x80000000) return 1/(pow(x, -(n + 1)) * x) //这里怎么有的时候可以通过，
             //有的时候却不能通过？以后再改。
             return 1/pow(x, -n);//int范围 [-2^31, 2^31-1] 小心-n溢出。
         }
     }
     double pow(double x, int n) {
         if(n == 0) return 1;
         if(n == 1) return x;
         if(n % 2){
             double temp = pow(x, n / 2);
             return temp * temp * x;
         }
         else{
             double temp = pow(x, n / 2);
             return temp * temp;
         }
     }
     //另一种写法，看起来更简洁
     double pow(double x, int n){
       if(n == 0) return 1;
       if(n == 1) return x;
       if(n % 2 == 0){
           return pow(x * x, n / 2);
       }
       else{
           return pow(x, n - 1) * x;
       }
     }
     //递推的写法
     //11 = (1011)
     //a^11 = a^(2^0) * a^(2^1) * a^(2^3);
     double pow(double x, int n) {
     	if (n == 0) return 1;
     	double ans = 1.0;
     	while (n) {
     		if (n & 1)
     			ans *= x;
     		x *= x;
     		n >>= 1;
     	}
     	return ans;
     }
 };

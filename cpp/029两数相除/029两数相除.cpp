/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
*/

//解答：一开始想着处理好负号以及溢出后用减法实现，但会时间超出，如下
#include <iostream>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
using namespace std;
/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        int result = 0;
        if(divisor == 1)
            return dividend;
        
        if(dividend >= 0 && divisor > 0)
        {
            while(dividend - divisor >= 0)
            {
                dividend -= divisor;
                result += 1;
            }
        }
        else if(dividend <= 0 && divisor < 0)
        {
             while(dividend - divisor <= 0)
            {
                dividend -= divisor;
                result += 1;
            }
            if(result < 0)
                result = INT_MAX;
        }
        else if(dividend <= 0 && divisor > 0)
        {
            while(dividend + divisor <= 0)
            {
                dividend += divisor;
                result += -1;
            }
        }
        else if(dividend >= 0 && divisor < 0)
        {
            while(dividend + divisor >= 0)                                               
            {
                dividend += divisor;
                result += -1;
            }
        }
     
        return result;
  
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
};
*/     
//解答：考虑到时间因素，这里使用了左移操作，将被除数看成除数*（2^n + 2^x + ……）,看成除数和若干个2的几次方相乘，这样使用左移和减法一起，每次减去 比被除数小的
//且是最大的除数乘以2的几次方，然后更新被除数，以此类推直到被除数小于除数为止
class Solution {
public:
    int divide(int dividend, int divisor) {
        //处理溢出
        long long a = (long long)dividend;
        long long b = (long long)divisor;
        if(b == 1)
            return dividend;
        if(b == -1)
        {
            if(a == INT_MIN)
            {
                return INT_MAX;
            }
            else
                return -a;
        }
        
        bool flag = true;
        if(a < 0)
        {
            flag = false;
            a = -a;
        }
        
        if(b < 0)
        {
            flag = !flag;
            b = -b;
        }
        
        //通过移位操作
        long long temp;
        long long result = 0;
        long long cur;
        while(a >= b)
        {
            temp = b;
            cur = 1;
            while(a >= (temp << 1))
            {
                temp <<= 1;
                cur <<= 1;
            }

            a -= temp;
            result += cur;
        }
        
        if(!flag)
            result = -result;
        
        if(result < INT_MIN || result > INT_MAX)
            result = INT_MAX;
        
        return result;
    }
};
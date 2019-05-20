/*
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/

//解答：小于n的每个数判断是否为质数即可
#include <cmath>
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i = 2; i < n; i++)
        {
            if(isPrime(i))
                count++;
        }
        
        return count;
    }
    
    bool isPrime(int n)
    {
        if(n <= 1)
            return false;
        
        int limit = sqrt(n);
        for(int i = 2; i <= limit; i++)
        {
            if(n % i == 0)
                return false;
        }
        
        return true;
    }
};
/*
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false
*/
//解答：对0特殊判断。对其他数一直除以2到除不尽为止，然后和1比较
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        while(n % 2 == 0)
        {
            n /= 2;
        }
        
        return n==1;
    }
};
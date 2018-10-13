/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/
//解决，反转后进行比较，虽然过了，但是实际上可能有溢出问题：
/*
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int temp = x;
        int result = 0;
        do{
            result = result * 10 + temp % 10;
            temp /= 10;
        }while(temp > 0);
        if(result == x)
            return true;
        else
            return false;
    }
};
*/

//只反转后半部分的代码如下，要注意位数只有奇数位时，反转的后半部分如果除以10和前半部分相等也是回文数，这样速度会比较快
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x!= 0 && x % 10 == 0)) //排除负数和10的倍数的情况
            return false;
       
        int result = 0;
        while(x > result)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
        
        if(x == result)
            return true;
        else if(result / 10 == x)
            return true;
        else
            return false;
    }
};
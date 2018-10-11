/*
给定一个 32 位有符号整数，将整数中的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。

*/
//解答，先把该数都转为正数，如果超出范围最后会变成负数，用这个判断是否溢出。使用栈来完成反转操作。
#include <stack>
#include <cmath>
class Solution {
public:
    int reverse(int x) {
        stack<int> s;
        int result = 0;
        bool flag = true;
        if(x < 0)
        {
            flag = false;
            x = -x;
        }
        
        do
        {
            s.push(x % 10);
            x = x / 10;
        }while(x > 0);
        
        int i = 0;
        while(!s.empty())
        {
            result += s.top() * pow(10, i++);
            s.pop();
        }
        
        if(result < 0)
            return 0;
        
        if(!flag)
            result = -result;
        
        return result;
    }
};
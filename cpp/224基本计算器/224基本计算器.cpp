/*
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。

示例 1:

输入: "1 + 1"
输出: 2
示例 2:

输入: " 2-1 + 2 "
输出: 3
示例 3:

输入: "(1+(4+5+2)-3)+(6+8)"
输出: 23
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

*/
//解答：维护一个数字栈一个符号栈，遇到数字则遍历到不是数字后将其加入数字栈， 遇到符号则先判断符号栈有无符号，有的话则弹出两个数字和符号进行运算
//遇到右括号则一直运算到左括号为止
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> signs;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
                continue;
            else if(s[i] >= '0' && s[i] <= '9')
            {
               int num = 0;
               while(i < s.length() && s[i] >= '0' && s[i] <= '9')
               {
                   num *= 10;
                   num += s[i] - '0';
                   i++;
               }
                i--;
                nums.push(num);
            }
            else if(s[i] == ')')
            {
                while(signs.top() != '(')
                {
                    char temp = signs.top();
                    signs.pop();
                    int num2 = nums.top();
                    nums.pop();
                    int num1 = nums.top();
                    nums.pop();
                    if(temp == '+')
                        nums.push(num1 + num2);
                    else
                        nums.push(num1 - num2);
                }
                signs.pop();
            }
            else if(s[i] == '(')
            {
                signs.push(s[i]);
            }
            else 
            {
                if(!signs.empty() && signs.top() != '(')
                {
                    char temp = signs.top();
                    signs.pop();
                    int num2 = nums.top();
                    nums.pop();
                    int num1 = nums.top();
                    nums.pop();
                    if(temp == '+')
                        nums.push(num1 + num2);
                    else
                        nums.push(num1 - num2);
                }
                
                
                signs.push(s[i]);
            }

        }
        
        if(!signs.empty())
        {
            char temp = signs.top();
            signs.pop();
            int num2 = nums.top();
            nums.pop();
            int num1 = nums.top();
            nums.pop();
            if(temp == '+')
                nums.push(num1 + num2);
            else
                nums.push(num1 - num2);
        }
        
        return nums.top();
    }
};
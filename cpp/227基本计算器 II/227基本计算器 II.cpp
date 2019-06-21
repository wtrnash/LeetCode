/*
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

示例 1:

输入: "3+2*2"
输出: 7
示例 2:

输入: " 3/2 "
输出: 1
示例 3:

输入: " 3+5 / 2 "
输出: 5
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。

*/

//解答：直接使用数字栈和符号栈，然后对加减和乘除分别赋予优先级后来做，倒数第二个用例会超出内存
/*
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> signs;
        int i = 0;
        int n = s.size();
        unordered_map<char, int> m;
        m['+'] = 1;
        m['-'] = 1;
        m['*'] = 2;
        m['/'] = 2;
        while(i < n)
        {
            if(s[i] == ' ')
            {
                i++;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                int j = i;
                while(j < n && s[j] >= '0' && s[j] <= '9')
                {
                    j++;
                }
                int num = atoi(s.substr(i, j).c_str());
                nums.push(num);
                i = j;
            }
            else 
            {
                while(!signs.empty())
                {
                    char temp = signs.top();
                    if(m[temp] >= m[s[i]])
                    {
                        signs.pop();
                        int num2 = nums.top();
                        nums.pop();
                        int num1 = nums.top();
                        nums.pop();
                        int result;
                        if(temp == '+')
                        {
                            result = num1 + num2;
                        }
                        else if(temp == '-')
                        {
                            result = num1 - num2;
                        }
                        else if(temp == '*')
                        {
                            result = num1 * num2;
                        }
                        else
                        {
                          result =  num1 / num2; 
                        }
                        nums.push(result);
                        
                    }
                    else
                        break;
                }
                 signs.push(s[i]);
                i++;
            }
        }
        while(!signs.empty())
        {
             char temp = signs.top();
             signs.pop();
             int num2 = nums.top();
             nums.pop();
             int num1 = nums.top();
             nums.pop();
             int result;
             if(temp == '+')
            {
                result = num1 + num2;
            }
            else if(temp == '-')
            {
                result = num1 - num2;
            }
            else if(temp == '*')
            {
                result = num1 * num2;
            }
            else
            {
                result =  num1 / num2; 
            }
            nums.push(result);
        }
        
        return nums.top();
    }
};

*/

//解答：只用数字栈，用一个字符记录上一个符号。然后先计算完乘除法，最后统一加一遍即可。
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
       int result = 0, d = 0;
        char sign = '+';
        stack<int> nums;
        for(int i = 0; i <s.size(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                d = d * 10 + (s[i] - '0');
            }
            if((s[i] < '0' && s[i] != ' ') || i == s.size() - 1)
            {
                if(sign == '+')
                {
                    nums.push(d);
                }
                else if(sign == '-')
                {
                    nums.push(-d);
                }
                else if(sign == '*' || sign == '/')
                {
                    int temp = sign == '*'? nums.top() * d: nums.top() / d;
                    nums.pop();
                    nums.push(temp);
                }
                sign = s[i];
                d = 0;
            }
        }
        
        while(!nums.empty())
        {
            result += nums.top();
            nums.pop();
        }
        
        return result;
    }
};
/*
根据逆波兰表示法，求表达式的值。

有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
示例 1：

输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9
示例 2：

输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6
示例 3：

输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
输出: 22
解释: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

//解答：利用栈存储数字，遇到运算符则弹出倒数两个数进行计算再压栈，直到遍历完为止
#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
#include <csdtio>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int result = 0;
        if(tokens.size() == 0)
            return result;
        
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i].length() > 1 || (tokens[i][0] >= '0' && tokens[i][0] <= '9'))
                s.push(atoi(tokens[i].c_str()));
            else
            {
                int temp2 = s.top();
                s.pop();
                int temp1 = s.top();
                s.pop();
                
                switch(tokens[i][0]){
                    case '+':
                        s.push(temp1 + temp2);
                        break;
                    case '-':
                        s.push(temp1 - temp2);
                        break;
                    case '*':
                        s.push(temp1 * temp2);
                        break;
                    case '/':
                        s.push(temp1 / temp2);
                        break;
                }
            }
        }
        
        return s.top();
        
    }
};
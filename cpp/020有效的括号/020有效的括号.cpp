/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
*/

//利用栈来判断即可，左括号则压入，右括号则判断栈是否为空以及栈顶是否匹配，最后输入完后判断栈是否为空
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                sta.push(s[i]);
            else if(s[i] == ')')
            {
                if(sta.empty() || sta.top() != '(')
                    return false;
                
                sta.pop();
            }
            else if(s[i] == ']')
            {
                if(sta.empty() || sta.top() != '[')
                    return false;
                
                sta.pop();
            }
            else
            {
                if(sta.empty() || sta.top() != '{')
                    return false;
                
                sta.pop();
            }
        }
        
        if(sta.empty())
            return true;
        else
            return false;
    }
};
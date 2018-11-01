/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

//解答 在左括号数小于n时可以添加左括号，在右括号小于左括号时可以添加右括号，然后递归地进行即可
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addParenthesis(result, "", 0, 0, n);
        return result;
    }
    
    void addParenthesis(vector<string>& result, string current, int left, int right, int n)
    {
        if(current.length() == 2*n)         //当长度等于2n时加入结果
        {
            result.push_back(current);
            return;
        }
            
        
        if(left < n)    //左括号小于n
        {
            addParenthesis(result, current + "(", left + 1, right, n);
        }
        
        if(right < left)    //右括号小于左括号
        {
            addParenthesis(result, current + ")", left, right + 1, n);
        }
    }
};
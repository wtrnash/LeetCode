/*
给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

示例 1:

输入: "2-1-1"
输出: [0, 2]
解释: 
((2-1)-1) = 0 
(2-(1-1)) = 2
示例 2:

输入: "2*3-4*5"
输出: [-34, -14, -10, -10, 10]
解释: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

*/
//解答：用递归，把每个符号分成左右两部分，然后分别按符号运算结果
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i = 0; i < input.size(); i++)
        {
            if(input[i] < '0' || input[i] > '9')
            {
                vector<int> r1 = diffWaysToCompute(input.substr(0, i));
                vector<int> r2 = diffWaysToCompute(input.substr(i + 1));
                for(int r : r1)
                {
                    for(int q: r2)
                    {
                        if(input[i] == '+')
                        {
                            result.push_back(r + q);
                        }
                        else if(input[i] == '-')
                        {
                             result.push_back(r - q);
                        }
                        else
                        {
                             result.push_back(r * q);
                        }
                    }
                 }
                
            } 
        }
        
        if(result.empty())
        {
            result.push_back(stoi(input));
        }
        
        return result;
    }
    
   
};
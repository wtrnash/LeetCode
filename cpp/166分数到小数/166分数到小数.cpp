/*

给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。

如果小数部分为循环小数，则将循环的部分括在括号内。

示例 1:

输入: numerator = 1, denominator = 2
输出: "0.5"
示例 2:

输入: numerator = 2, denominator = 1
输出: "2"
示例 3:

输入: numerator = 2, denominator = 3
输出: "0.(6)"
*/

//解答：模拟除法。用map记录余数，如果余数重复出现，则为循环节。用Long Long防止溢出，处理好负号。
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long a = numerator, b = denominator;
        
        if(a % b == 0)
            return to_string(a / b);
        
        string result;
        if(a * b < 0)
        {
            if(a / b == 0)
                result += "-0.";
            else
                result += to_string(a / b) + ".";
        } 
        else
            result += to_string(a / b) + ".";
        
        unordered_map<long long, int> m;
        long long c = abs(a % b);
        while(c != 0)
        {
            c *= 10;
            long long d = abs(c % b);
            long long e = abs(c / b);

            if(m.find(c) != m.end())
            {
                int index = m[c];
                result = result.substr(0, index) + "(" + result.substr(index) + ")";
                return result;
            }
            else
            {
                m[c] = result.size();
                result += to_string(e);
            }
            
            c = d;
        }
        
        return result;
        
       
    }
};
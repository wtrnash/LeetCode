/*
验证给定的字符串是否为数字。

例如:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。

*/

//解答：将字符分成 正负号、e、数字、小数点、空格和其他字符六类，分别处理即可。
#include <string>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        //初始阶段没有数字， 没有E所以E后的数字暂时是true，没有小数点、e和正负号
       bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == ' ')     //如果是空格
            {
                if(i < n - 1 && (num || dot || exp || sign) && s[i + 1] != ' ') //不是最后的空格的情况下，如果已经有过数字、正负号、e或小数点，且下一个字符不是空格，则违规
                    return false;
            }
            else if(s[i] == '+' || s[i] == '-')         //如果是正负号
            {
                if(i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') //前一个不是e或空格就违规
                    return false;
                
                sign = true;
            }
            else if(s[i] == '.')    //小数点只能出现一次，并且要在e之前出现
            {
                if(dot || exp)
                   return false;
                
                dot = true;
            }
            else if(s[i] == 'e')    //e只能出现一次，而且之前需要出现数字
            {
                if(exp || !num)
                     return false;
                
                exp = true;
                numAfterE = false;  //出现e后，numAfterE就有效，需要后面有出现数字才合法
            }
            else if(s[i] >= '0' && s[i] <= '9') //出现数字
            {
                num = true;
                numAfterE = true;
            }
            else    //其他字符则违规
                return false;
        }
        
        return num && numAfterE;    //返回e前的数字和e后的数字，两者都合法才为true
    }
};
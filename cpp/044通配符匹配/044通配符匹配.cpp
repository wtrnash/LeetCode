/*
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
示例 3:

输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
示例 4:

输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
示例 5:

输入:
s = "acdcb"
p = "a*c?b"
输入: false
*/

//解答：主要处理*号，用贪心算法，*从匹配0个字符开始，如果后面不匹配再跳回该点，匹配1个字符，以此类推。如果s匹配完，再判断p中剩下字符是不是都是*。
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int indexS = 0;
        int indexP = 0;
        int starS = -1;
        int starP = -1;
        while(indexS < s.length())
        {
            if(indexP < p.length() && (s[indexS] == p[indexP] || p[indexP] == '?')) //判断当前是否相等，或者p为？
            {
                indexS++;
                indexP++;
            }
            else if(indexP < p.length() && p[indexP] == '*')    //如果当前p为*，记录starp的位置，以及s遇到p为*时所在的位置
            {
                starP = indexP++;
                starS = indexS;
            }
            else if(starP >= 0) //如果之前存在遇到过*，则indexS为starS的下一个位置，即*再多匹配一个字符
            {
                indexS = starS++;
                indexP = starP + 1;
            }
            else    //不是上述情况则直接返回false
                return false;
        } 
        
        while(indexP < p.length())  //s匹配完后看p之后是否都为*
        {
            if(p[indexP++] != '*')
                return false;
            
        }
        
        return true;
        
    }
};
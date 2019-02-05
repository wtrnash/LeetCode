/*
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
*/
//解答：递归来做，每次处理前两个字符。如果为空或只有一个字符且不为0，则返回1。如果前两个字符大于26，那只能第一个字符作为单独处理。 其他情况就分成把第一个提出来和前两个提出来的情况
#include <string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        return recursion(s); 
    }
    
    int recursion(string s)
    {
        if(s.length() == 0)
            return 1;
        
        if(s[0] == '0')
            return 0;
        
        if(s.length() == 1)
            return 1;
        
        
        if(s[0] - '0' >= 3 || (s[0] - '0' == 2 && s[1] - '0' > 6))
        {
            return recursion(s.substr(1));
        }
        
        
        return recursion(s.substr(1)) + recursion(s.substr(2));
    }
    
};
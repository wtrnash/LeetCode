/*
给定一个字符串，逐个翻转字符串中的每个单词。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

*/

//解答：依次处理整个字符串，遇到空格则判断是否已经有字符，有的话加入栈。最后将栈里的依次加入结果即可
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        if(s.length() == 0)
            return "";
        
        string result = "";
        stack<string> s2;
        string temp = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
              if(temp == "")
                  continue;
                else
                {
                    s2.push(temp);
                    temp = "";
                }
            }
            else
            {
                temp += s[i];
            }
        }
        
        if(temp != "")
            s2.push(temp);
        
        while(!s2.empty())
        {
            result += s2.top();
            s2.pop();
            if(!s2.empty())
                result += " ";
        }
        
        return result;
        
    }
};
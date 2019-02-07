/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/

//解答：用递归去处理，每次根据当前长度处理 1~3个字符。处理4次结束，如果此时s还有字符，则不加入结果。 要注意第一次处理不用前面加'.'，以及0开头的话就不能加两个或三个的字符
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string temp;
        if(s.length() < 4)
            return result;
        recursion(result, temp, s, 0);
        return result;
    }
    
    void recursion(vector<string>& result, string temp, string s, int index)
    {
        if(index == 4)
        {
            if(s.empty())
            {
                result.push_back(temp);
            }
            
            return;
        }
        
        if(s.empty())
            return;
        
        if(index == 0)
        {
            temp.push_back(s[0]);
            recursion(result, temp, s.substr(1) ,index + 1);
          
            if(s[0] == '0')
                return;
            temp.push_back(s[1]);
            recursion(result, temp, s.substr(2) ,index + 1);
            
            if((s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0') < 256)
            {
                temp.push_back(s[2]);
                recursion(result, temp, s.substr(3) ,index + 1);
            }
        }
        else
        {
            temp.push_back('.');
            temp.push_back(s[0]);
            recursion(result, temp, s.substr(1) ,index + 1);
            if(s.length() < 2 || s[0] == '0')
                return;
            temp.push_back(s[1]);
            recursion(result, temp, s.substr(2) ,index + 1);
            
             if(s.length() < 3)
                return;
            if((s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0') < 256)
            {
                temp.push_back(s[2]);
                recursion(result, temp, s.substr(3) ,index + 1);
            }
        }
       
    }
    
    
};
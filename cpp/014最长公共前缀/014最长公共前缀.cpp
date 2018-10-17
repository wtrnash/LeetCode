/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

//解答 以第一个字符串作为基准，每个字符都和剩余字符串组对应位置的字符串进行比较，相等则继续，不相等则直接返回结果，注意判空和数组越界即可
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if(strs.size() == 0)    //输入为空
            return result;
        for(int j = 0; j < strs[0].length(); j++)
        {
            char temp = strs[0][j];
            for(int i = 1; i < strs.size(); i++)
            {
                if(strs[i].length() <= j)
                    return result;
                
                if(strs[i][j] != temp)
                    return result;
            }
            
            result += temp;
        }
        
        return result;

    }
};
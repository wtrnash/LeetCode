/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5
*/

//简单题。从字符串最后开始往前遍历，遇到空格不计数。遇到第一个单词开始计数，一直到再次遇到空格后跳出返回结果
//这题提交成功率低的原因应该还是在理解题意上，有人可能会认为如果从后往前遍历遇到第一个空格那么直接返回0
//但实际上应该遍历到遇到第一个单词再计数
#include  <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(count == 0 && s[i] == ' ')
                continue;
            
            if(s[i] != ' ')
                count++;
            
            if(count != 0 && s[i] == ' ')
                break;
        }
        
        return count;
    }
};
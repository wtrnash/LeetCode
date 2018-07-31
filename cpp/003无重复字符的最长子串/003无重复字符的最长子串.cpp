/*
题目：
给定一个字符串，找出不含有重复字符的最长子串的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。
*/

/*
解答：
每个元素作为开头，开始向后滑动，后面的元素作为结尾和前面所有元素进行比较，判断是否重复。
*/
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        string temp = "";
        //子串以每个元素开头都要遍历一次
        for(int i = 0; i < s.length(); i++)
        {
            //将开头加入子串
            temp.append(1, s[i]);

            //判断到哪个元素结尾
            int j;
            for(j = i + 1; j < s.length(); j++)
            {
                int k;
                //判断是否重复
               for(k = 0; k < temp.length(); k++)
               {
                   if(temp[k] == s[j])
                   {
                        if(temp.length() > maxLength)   //遇到重复要重新计算，所以判断当前子串的长度是否最长
                            maxLength = temp.length();
                        break;
                   }
               } 

                //没有重复则加入
               if(k == temp.length())
               {
                    temp.append(1, s[j]);
               }
                else    //否则清空该子串，跳出该循环
                {
                    temp.clear();
                    break;
                }
                   
            }

            if(j == s.length())      //处理遍历到末尾没遇到重复的情况
            {
                if(temp.length() > maxLength)   
                    maxLength = temp.length();
                break;   
            }
                 
        }

        return maxLength;
    }
};


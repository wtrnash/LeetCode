/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
*/

//解答： 二重循环，每次选择一个字符作为起始点，如果右括号增加后使得右括号左括号数目达到一致，则为有效括号串，更新当前子串长度，如果右括号增加后数量大于左括号数，则不合法跳出循环
//比较每个子循环记录的长度和最大长度，如果大于最大长度则更新
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
      if(s.length() == 0)
          return 0;
      int maxLength = 0;
      int currentLength;
      int j;
      int left;
      int right;
      for(int i = 0; i < s.length(); i++)
      {
          left = 0;
          right = 0;
          currentLength = 0;
          for(j = i; j < s.length(); j++)
          {
               if(s[j] == '(')
               {
                    left++;
               }
              else
              {
                   right++;
                  if(right > left)
                  {
                      break;
                  }
                  else if(right == left)
                  {
                      currentLength = j - i + 1;
                  }
              }
              
          }
          
          if(currentLength > maxLength)
        {
            maxLength = currentLength;          
        }
      }
        
        return maxLength;
    }
};
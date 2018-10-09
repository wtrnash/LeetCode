/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/

//一开始直接暴力求解，对每一个开头和结尾都判断是否是回文串，时间复杂度O(n^3)， 会时间超出：
/*
class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        if(s.length() == 0)
            result = "";
        else
            result = s[0];
        
        for(int i = 0; i < s.length(); i++)
        {
            for(int j = 1; j <= s.length(); j++)
            {
                string substr = s.substr(i, j);
                if(isPalindrome(substr) && (substr.length() > result.length()))
                {
                    result = substr;
                }
            }
        }
        
        return result;
    }
    
    bool isPalindrome(string s){
        bool result = true;
        for(int i = 0; i <= (s.length() - 1) / 2; i++)
        {
            if(s[i] != s[s.length() - 1 -i])
            {
                result = false;
                break;
            }
        }
        
        return result;
    }
};
*/

//所以采用动态规划方法，使得时间复杂度变成O(n^2)，即p(i,j)当p(i+1, j-1)为回文且s[i] = s[j]时也为回文
class Solution {
public:
    string longestPalindrome(string s) {
      int len = s.length();
      if(len == 0)
          return "";
    
      //二维数组记录开头为i和末尾为j的子串是否为回文串
      bool p[len][len];
      for(int i = 0; i < len; i++)
          for(int j = 0; j < len; j++)
              p[i][j] = false;
        
      //初始化一字符和二字符的回文串
      for(int i = 0; i < len; i++)
      {
          p[i][i] = true;
          if(i != len - 1 && s[i] == s[i+1])
          {
              p[i][i+1] = true;
          }
      }
      
      //从三字符开始推导，动态规划处理完所有的子串
      for(int j = 2; j < len; j++)
      {
          for(int i = 0; i < len, i + j < len; i++)
          {
              if(p[i + 1][i + j - 1] && s[i] == s[i + j])
                  p[i][i + j] = true;
          }
      }
      
      //找出最长回文串
      int start = 0, end = 0;
      for(int i = 0; i < len; i++)
      {
          for(int j = 0; j < len; j++)
          {
              if(p[i][j] && (j - i + 1) > (end -start + 1))
              {
                  start = i;
                  end = j;
              }
          }
      }
        
       return s.substr(start, end - start + 1);
    }
        
        
};
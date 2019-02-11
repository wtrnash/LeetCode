/*
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
*/

//解答：一开始想，遍历s3，遇到和一个相同的则索引自增，如果两个都相同则递归分别进行。如果都不相同则直接返回false，但是用例超时
/*
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return recursion(s1, s2, s3);
    }
    
    bool recursion(string s1, string s2, string s3)
    {
        if(s1.empty() && s2.empty())
            return s3.empty();
        
        if(s3.empty())
            return s1.empty() && s2.empty();
        
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        int j = 0;
        int k = 0;
        for(int i = 0; i < s3.size(); i++)
        {
            if(j < s1.size() && s1[j] == s3[i])
            {
                if(k < s2.size() && s2[k] == s3[i])
                {
                    return recursion(s1.substr(j + 1), s2.substr(k), s3.substr(i + 1)) ||
                            recursion(s1.substr(j), s2.substr(k + 1), s3.substr(i + 1));
                }
                else
                {
                    j++;
                    continue;
                }
                
            }
            
            if(k < s2.size() && s2[k] == s3[i])
            {
                k++;
            }
            else
            {
                return false;
            }
             
        }
        
        if(j == s1.size() && k == s2.size())
            return true;
        else
            return false;
    }
};
*/

//解答：然后用动态规划做。 dp[i][j]表示s1前i个元素和s2前j个元素和s3前i+j个元素是否为交错字符串
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        
        vector<vector <bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, true));
        
        for(int i = 1; i <= s1.size(); i++)
        {
            dp[i][0] = (s1[i - 1] == s3[i - 1]) && dp[i - 1][0];
        }
        
        for(int j = 1; j <= s2.size(); j++)
        {
            dp[0][j] = (s2[j - 1] == s3[j - 1]) && dp[0][j - 1];
        }
        
        for(int i = 1; i <= s1.size(); i++)
        {
            for(int j = 1; j <= s2.size(); j++)
            {
                dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) ||
                    (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
            }
        }
        
        return dp[s1.size()][s2.size()];
    } 
    
  
};
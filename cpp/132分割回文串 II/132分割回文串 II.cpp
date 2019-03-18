/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

示例:

输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

*/

//解答：先用131的思路，dfs然后计算最少次数，结果超时如下。开头加上对于分割0次和1次的预处理仍然超时
#include <string>
#include <vector>
#define INT_MAX 2147483647 
using namespace std;
/*
class Solution {
public:
    int minCut(string s) {
        int min = INT_MAX;
        vector<string> temp;
        solve(min, temp, s, 0);
        return min;
    }
    
    void solve(int& min, vector<string>& temp, string s, int pos)
    {
        if(pos == s.length())
        {
            if(temp.size() - 1 < min)
                min = temp.size() - 1;
            return;
        }
        
        for(int i = pos; i < s.length(); i++)
        {
            string t = s.substr(pos, i - pos + 1);
            if(!isPalindrome(t))
                continue;
            temp.push_back(t);
            solve(min, temp, s, i + 1);
            temp.pop_back();
        }
        
        
    }
    
    bool isPalindrome(string& s)
    {
        if(s.length() == 0)
            return false;
        
        int begin = 0;
        int end = s.length() - 1;
        
        while(begin < end)
        {
            if(s[begin++] != s[end--])
                return false;
        }
        
        return true;
    }
};
*/

//使用dp做
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> judge(n, vector<bool>(n, false));  //judge[i][j]表示字符串s(i,j)是否是回文串
        for(int i = 0; i < n; i++)
            judge[i][i] = true;
        
        vector<int> dp(n, INT_MAX); //dp[i]表示第i个字符到第n-i个字符的最少分割次数
        for(int i = n - 1; i >= 0; i--)
        {
           for(int j = i; j < n; j++)
           {
               if(s[i] == s[j] && (j - i <= 1 || judge[i + 1][j - 1]))  //i,j相等且 i 到 j的距离小于1或者 s(i + 1, j - 1)为回文串，则s(i, j)为回文串
               {
                   judge[i][j] = true;
                   if(j + 1 < n)
                   {
                       dp[i] = min(dp[i], 1 + dp[j + 1]);       // 更新dp[i]， 这次求出的dp[i]值为 分割s(i,j)和s(j + 1, n-1)需要的1次以及分割s(j+1, n-1)需要的dp[j + 1]次
                   }
                   else
                   {
                       dp[i] = 0;   //如果j = n - 1,说明 s(i ,n - 1)为回文串，所以 dp[i]为0
                   }
               }
           }
        }
        
        return dp[0];
    }
    
 
};
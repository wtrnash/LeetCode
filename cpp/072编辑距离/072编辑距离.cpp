/*
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
示例 1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2:

输入: word1 = "intention", word2 = "execution"
输出: 5
解释: 
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/

//解答：使用动态规划做。 开一个dp[m + 1][n + 1]的数组， dp[i][j]表示 word1 i个字符转换为 word2 j个字符需要的最少操作数
//知道dp[i][j]后，如果 word1[i]和word2[j]相等，则 dp[i + 1][j + 1] = min(dp[i][j], dp[i][j + 1] + 1, dp[i + 1][j] + 1)
//因为此时在dp[i][j]的基础上不需要操作即可转换，所以次数和dp[i][j]相同，而如果用dp[i][j + 1]的话，需要把word1[i]删了才行,所以要在这基础上 + 1
//用dp[i + 1][j]的话需要插入一个word2[j]，所以也需要+1。然后在这三个里取最小即可
//如果不相等dp[i][j也需要+ 1
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector <int>> dp(m + 1, vector<int>(n + 1, 0));  
        for(int i = 0; i <= m; i++) //从i个字符变成0个字符最小需要i个操作数
            dp[i][0] = i;
        for(int i = 0; i <= n; i++) //从0个字符变成i个字符最小需要i个操作数
            dp[0][i] = i;
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j] + 1), dp[i][j - 1] + 1);
                else
                    dp[i][j] = min(min(dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1), dp[i][j - 1] + 1);
            }
        }
        
        return dp[m][n];
    }
}; 
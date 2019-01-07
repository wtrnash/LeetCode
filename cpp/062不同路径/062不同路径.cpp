/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？



例如，上图是一个7 x 3 的网格。有多少可能的路径？

说明：m 和 n 的值均不超过 100。

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28
*/

//解答：先直接用dfs，结果超时，代码如下
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        return dfs(1, 1, m, n);
    }
    
    int dfs(int x, int y, int m, int n)
    {
        if(x == m && y == n)
            return 1;
        
        int nums = 0;
        if(x < m)
            nums += dfs(x + 1, y, m, n);
        
        if(y < n)
            nums += dfs(x, y + 1, m, n);
        
        return nums;
    }
};
*/

//然后想到用动态规划做，当前格子的路径数等于上面格子的路径数+左边格子的路径数。初始化第一行、第一列路径数都为1，动态规划即可
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector <int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            dp[0][i] = 1;
        for(int i = 0; i < m; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        
        return dp[m - 1][n - 1];
    }
    
  
};
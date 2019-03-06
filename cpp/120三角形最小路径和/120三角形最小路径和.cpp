/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
*/


//解答：动态规划：从下往上，每一层的值为下一层相邻的两个中的最小值加上当前值，该版本为二维数组dp版本
#include <vector>
#include <cmath>
using namespace std;
/*
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int result = 0;
        int n = triangle.size();
        if(n == 0)
            return result;
        
        vector<vector <int>> dp(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++)
            dp[n - 1][i] = triangle[n - 1][i];
        
        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        
        return dp[0][0];
    }
};
*/

//用O(n)空间复杂度版本
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int result = 0;
        int n = triangle.size();
        if(n == 0)
            return result;
        
        vector <int> dp(n, 0);
        
        for(int i = 0; i < n; i++)
            dp[i] = triangle[n - 1][i];
        
        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        
        return dp[0];
    }
};
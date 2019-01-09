"""
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
"""

# 解答：用动态规划做。当前坐标的最小路径和为当前的数字加上上面和左边里较小的路径和。dp可以只用一维数组，每次只表示当行的情况，然后下行覆盖上一行，达到压缩空间的目的
class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        dp = [0 for i in range(n)]
        dp[0] = grid[0][0]
        for i in range(1,n):
            dp[i] = dp[i - 1] + grid[0][i]
        
        for i in range(1, m):
            dp[0] = dp[0] + grid[i][0]
            for j in range(1, n):
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j]
        
        return dp[n - 1]
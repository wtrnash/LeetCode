"""
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4

"""
# 解答：用动态规划做。dp[i][j]记录以i,j为右下角的最大正方形的边长。 那么i，j要能组成最大正方形，其左边、上面和左上就必须全部是1，所以
# 状态转移方程为dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j])
class Solution:
    def maximalSquare(self, matrix) -> int:
        n = len(matrix)
        if n == 0:
            return 0
        
        m = len(matrix[0])
        if m == 0:
            return 0
        dp = [[0 for x in range(m)] for y in range(n)]
        
        result = 0
        for i in range(n):
            if matrix[i][0] == '1':
                dp[i][0] = 1
                result = 1
        
        for j in range(m):
            if matrix[0][j] == '1':
                dp[0][j] = 1
                result = 1
        
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j] == '1':
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j])
                    result = max(result, dp[i][j])
                    
        
        return result * result
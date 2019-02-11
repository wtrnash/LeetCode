"""
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
"""

# 解答：用动态规划做。 dp[i][j]表示s1前i个元素和s2前j个元素和s3前i+j个元素是否为交错字符串
class Solution:
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        m = len(s1)
        n = len(s2)
        if not m + n == len(s3):
            return False
        
        dp = [[False for i in range(n + 1)] for j in range(m + 1)]
        dp[0][0] = True
        for i in range(m + 1):
            for j in range(n + 1):
                if i > 0:
                    dp[i][j] = dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]
                if j > 0:
                    dp[i][j] = dp[i][j] or dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]
        
        return dp[m][n]
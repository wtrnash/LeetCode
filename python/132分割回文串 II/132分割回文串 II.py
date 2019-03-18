"""
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

示例:

输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

"""
# 解答：动态规划
class Solution:
    def minCut(self, s: str) -> int:
        if s == s[::-1]:    # 判断整个字符串是否回文
            return 0
        
        n = len(s)
        judge = [[False for x in range(n)] for y in range(n)]   # judge[i][j]表示字符串s(i,j)是否是回文串
        dp = [2 ** 31 for x in range(n)]    # dp[i]表示第i个字符到第n-i个字符的最少分割次数
        
        for i in range(n - 1, -1, -1):
            for j in range(i, n):
                if s[i] == s[j] and (j - i <= 1 or judge[i + 1][j - 1]):    # i,j相等且 i 到 j的距离小于1或者 s(i + 1, j - 1)为回文串，则s(i, j)为回文串
                    judge[i][j] = True
                    if j + 1 < n:
                        dp[i] = min(dp[i], 1 + dp[j + 1])   #  更新dp[i]， 这次求出的dp[i]值为 分割s(i,j)和s(j + 1, n-1)需要的1次以及分割s(j+1, n-1)需要的dp[j + 1]次
                    else:
                        dp[i] = 0   # 如果j = n - 1,说明 s(i ,n - 1)为回文串，所以 dp[i]为0
                        
        return dp[0]

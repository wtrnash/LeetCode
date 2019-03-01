"""
给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。

一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

示例 1:

输入: S = "rabbbit", T = "rabbit"
输出: 3
解释:

如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
示例 2:

输入: S = "babgbag", T = "bag"
输出: 5
解释:

如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
(上箭头符号 ^ 表示选取的字母)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^

"""

# 解答：利用动态规划做。子序列为空时，原字符串含有的子序列数量为1。 长度为j的原字符串包含长度为i的子序列的个数，当s[j-1]不等于t[i-1]时，和长度为j-1的原字符串包含长度为i的子序列的个数一样
# 如果相等，还要加上长度j-1的原字符串包含长度为i-1的子序列的个数
class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m = len(s) + 1
        n = len(t) + 1
        dp = [[0 for i in range(m)] for j in range(n)]
        for j in range(m):
            dp[0][j] = 1
            
        for i in range(1, n):
            for j in range(1, m):
                dp[i][j] = dp[i][j - 1]
                if s[j - 1] == t[i - 1]:
                    dp[i][j] += dp[i - 1][j - 1]
        
        return dp[n - 1][m - 1]
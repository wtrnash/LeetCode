"""
给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
示例 3:

输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
示例 4:

输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
示例 5:

输入:
s = "acdcb"
p = "a*c?b"
输入: false
"""

# 解答：使用动态规划做。两个都为空时即dp[0][0]为true， 从S第一个字符到第i个字符和p第一个字符到第j个字符是否匹配，如果当前p[j]不为*，则取决于之前
# dp[i - 1][j -1]的是否匹配以及s[i - 1]和p[i - 1]是否相等或者p[i - 1]是否为？;如果为*，则取决于dp[i - 1][j] 或 dp[i] [j - 1]的状态
class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        dp = [[False for col in range(len(p) + 1)] for row in range(len(s) + 1)] # 初始化为 (len(s) + 1 ) * (len(p) + 1)
        dp[0][0] = True # 两个都为空时匹配
        for i in range(1, len(p) + 1):      # 如果i-1为*, 则当前的状态和上一个状态一样
            if p[i - 1] == '*':
                dp[0][i] = dp[0][i - 1]
    
        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                    if not p[j - 1] == '*': # 不为*时
                        dp[i][j] = dp[i - 1][j - 1] and (s[i - 1] == p[j - 1] or p[j - 1] == '?')
                    else:
                        dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
                        
        return dp[len(s)][len(p)]
                    
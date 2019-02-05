"""
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
"""

# 解答：用动态规划做。类似于f[n] = f[n - 1] + f[n-2] ，要先判断当前位是否为0，为0的话，f[n - 1]就不起效果。 然后这两位是否在10到26之间，是的话f[n-2]才起效果
class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        dp = [0] * (len(s) + 1)
        
        dp[0] = 1
        for i in range(len(s)):
            if s[i] == '0':
                dp[i + 1] = 0
            else:
                dp[i + 1] = dp[i]
            
            if i > 0 and (s[i - 1] == '1' or s[i - 1] == '2' and s[i] <= '6'):
                dp[i + 1] += dp[i - 1]
            
        return dp[len(s)]
"""
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
"""
# 用暴力求解会时间超出，所以使用动态规划，使得时间复杂度变成O(n^2)，即p(i,j)当p(i+1, j-1)为回文且s[i] = s[j]时也为回文,其中i为起始，j为结尾，p(i,j)表示以下标i开头以j结尾的字符串是否是回文串
class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        # 初始化二维数组
        p = []
        for i in range(length):
            p.append([False] * length)
        
        # 处理一字符和二字符的回文串
        for i in range(length):
            p[i][i] = True
            if i != length - 1 and s[i] == s[i + 1]:
                p[i][i + 1] = True

        # 三字符以之前的结果可以推出，之后的同理        
        for j in range(2, length):
            for i in range(0, length):
                if i + j < length and p[i + 1][i + j - 1] and s[i] == s[i + j]:
                    p[i][i+j] = True
        
        # 找出最长回文串
        start = 0
        end = 0
        for i in range(length):
            for j in range(length):
                if p[i][j]  and (j - i + 1) > (end - start + 1):
                    start = i
                    end = j
        
        return s[start: end + 1]
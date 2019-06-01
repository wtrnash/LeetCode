"""

给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

示例 1:

输入: "aacecaaa"
输出: "aaacecaaa"
示例 2:

输入: "abcd"
输出: "dcbabcd"
"""

# 解答：取以开始为起点最长的回文子串，然后后一部分的反转作为开始
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        r = 1
        for i in range(len(s), 0, -1):
            if s[:i] == (s[:i])[::-1]:
                r = i
                break
                
        return (s[r:])[::-1] + s

"""
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
"""
# 解答：用动态规划做，详见下面注释

class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        f = [0] * n # 动态规划辅助函数，每个元素表示以当前下标开始往后的有效括号子串长度
        maxLength = 0 # 记录最长长度
        for i in range(n - 2, -1, -1):  # 逆序遍历
            if s[i] == '(': # 当前为左括号
                # i + 1为下一个元素，f[i+1]为下一个元素的有效子串长度，所以i + 1 + f[i + 1] 为跳过已经有效的子串，看后面一个是否为右括号
                if i + 1  + f[i + 1] < n and s[i + 1 + f[i + 1]] == ')' :
                    f[i] = 2 + f[i + 1]
                # 处理连续相邻有效子串的情况,即如果相邻的后面还是一个有效括号串，则也需要加入
                    if i + 1 + f[i + 1] + 1 < n:
                        f[i] = f[i] + f[i + 1 + f[i + 1] + 1]
                    if f[i] > maxLength:
                        maxLength = f[i]
                        
        return maxLength
            
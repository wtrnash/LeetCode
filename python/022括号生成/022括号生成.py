"""
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
"""

# 解答 在左括号数小于n时可以添加左括号，在右括号小于左括号时可以添加右括号，然后递归地进行即可
class Solution:
    def __init__(self):
        self.result = []
        
        
    def addParenthesis(self, current, left, right, n):
        if len(current) == 2 * n:
            self.result.append(current)
            return
        
        if left < n:
            self.addParenthesis(current+"(", left+1, right, n)
        
        if right < left:
            self.addParenthesis(current+")", left, right+1, n)
            
            
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.addParenthesis("", 0, 0, n)
        return self.result
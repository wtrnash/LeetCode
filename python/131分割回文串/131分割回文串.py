"""
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

"""

# 解答：递归，每次分割成功一个子串后，对剩下来的子串递归分割，一直到分割完则加入结果中
class Solution:
    def partition(self, s: str):
        if len(s) == 0:
            return []
        self.result = []
        self.path = []
        self.solve(s, 0)
        return self.result
    
    def solve(self, s, pos):
        if pos == len(s):
            self.result.append(self.path[:])
        
        for i in range(pos, len(s)):
            temp = s[pos:i+1]
            if not self.isPalindrome(temp):
                continue
            
            self.path.append(temp)
            self.solve(s, i + 1)
            self.path.pop()
        
    
    def isPalindrome(self, s):
        if len(s) == 0:
            return False
        
        begin = 0
        end = len(s) - 1
        while begin < end:
            if s[begin] != s[end]:
                return False
            begin += 1
            end -= 1
        
        return True
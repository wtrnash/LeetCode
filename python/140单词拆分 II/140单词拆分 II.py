"""
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]
示例 2：

输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。
示例 3：

输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]
"""


# 先使用dp判断s是否可分，再进行dfs
class Solution:
    def wordBreak(self, s: str, wordDict):
        result = []
        temp = ""
        self.dfs(result, temp, s, wordDict)
        return result
    
    def dfs(self, result, temp, s, wordDict):
        if len(s) == 0:
            result.append(temp[:])
            return
        
        if not self.isBreak(s, wordDict):
            return
        
        for word in wordDict:
            n = len(word)
            l = len(temp)
            if s[:n] == word:
                if l != 0:
                    temp = temp + " "
                temp = temp + word
                self.dfs(result, temp, s[n:], wordDict)
                temp = temp[:l]
            
    def isBreak(self, s, wordDict):
        n = len(s)
        dp = [False for x in range(n + 1)]
        dp[0] = True
        for i in range(1, n + 1):
            for j in range(0, i):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True

        return dp[n]
"""
给定一个单词列表和两个单词 word1 和 word2，返回列表中这两个单词之间的最短距离。

示例:
假设 words = ["practice", "makes", "perfect", "coding", "makes"]

输入: word1 = “coding”, word2 = “practice”
输出: 3
输入: word1 = "makes", word2 = "coding"
输出: 1
注意:
你可以假设 word1 不等于 word2, 并且 word1 和 word2 都在列表里。

"""

# 解答：分别记录word1和word2最近一次的索引，并和结果比较看距离是否更短，更短则更新
class Solution:
    def shortestDistance(self, words, word1: str, word2: str) -> int:
        index1 = -1
        index2 = -1
        n = len(words)
        result = n
        for i in range(n):
            if words[i] == word1:
                index1 = i
                if index2 != -1:
                    result = min(result, abs(index1 - index2))
            if words[i] == word2:
                index2 = i
                if index1 != -1:
                    result = min(result, abs(index1 - index2))
        
        return result
                
"""
给定一个单词列表和两个单词 word1 和 word2，返回列表中这两个单词之间的最短距离。

word1 和 word2 是有可能相同的，并且它们将分别表示为列表中两个独立的单词。

示例:
假设 words = ["practice", "makes", "perfect", "coding", "makes"].

输入: word1 = “makes”, word2 = “coding”
输出: 1
输入: word1 = "makes", word2 = "makes"
输出: 3
注意:
你可以假设 word1 和 word2 都在列表里。

"""
# 解答：类似243题，只是存在一样的单词，所以在word2更新结果的时候要判断下是否是一样的单词，一样的单词则只在word1的index改变时更新
class Solution:
    def shortestWordDistance(self, words, word1: str, word2: str) -> int:
        n = len(words)
        result = n
        index1 = -1
        index2 = -1
        for i in range(n):
            if words[i] == word1:
                index1 = i
                if index2 != -1:
                    result = min(result, abs(index1 - index2))
            
            if words[i] == word2:
                index2 = i
                if index1 != -1 and word1 != word2:
                    result = min(result, abs(index1 - index2))
        
        return result
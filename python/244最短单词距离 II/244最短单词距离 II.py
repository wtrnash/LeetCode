"""
请设计一个类，使该类的构造函数能够接收一个单词列表。然后再实现一个方法，该方法能够分别接收两个单词 word1 和 word2，并返回列表中这两个单词之间的最短距离。您的方法将被以不同的参数调用 多次。

示例:
假设 words = ["practice", "makes", "perfect", "coding", "makes"]

输入: word1 = “coding”, word2 = “practice”
输出: 3
输入: word1 = "makes", word2 = "coding"
输出: 1
注意:
你可以假设 word1 不等于 word2, 并且 word1 和 word2 都在列表里。
"""
# 解答：用哈希表记录各个单词出现的下标，等输入后由于初始下标即有序，所以哪个比较小就往后移，只要线性复杂度即可
from collections import defaultdict
class WordDistance:
    def __init__(self, words):
        self.m = defaultdict(list)
        n = len(words)
        for i in range(n):
            self.m[words[i]].append(i)
            
        self.n = n
    def shortest(self, word1: str, word2: str) -> int:
        a = self.m[word1]
        b = self.m[word2]
        l1 = 0
        l2 = 0
        result = self.n
        while l1 < len(a) and l2 < len(b):
            result = min(result, abs(a[l1] - b[l2]))
            if a[l1] < b[l2]:
                l1 += 1
            else:
                l2 += 1
        
        return result


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)
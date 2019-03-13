"""
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。

"""

# 解答：使用BFS,在127的基础上进行更改，会时间超出
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList):
        result = []
        paths = [[beginWord]]
        level = 1
        min_level = 2 ** 32
        word_dict = {}
        for word in wordList:
            word_dict[word] = 1
        words = {}
        character = 'abcdefghijkmnlopqrstuvwxyz'
        while paths:
            temp = paths.pop(0)
            if len(temp) > level:
                for word in words.keys():
                    word_dict.pop(word)
                level = len(temp)
                if level > min_level:
                    break
            
            last = temp[-1]
            for i in range(len(last)):
                new_last = last[:]
                for ch in character:
                    new_last = last[:i] + ch + last[i + 1:]
                    if new_last in word_dict.keys():
                        new_paths = temp[:]
                        new_paths.append(new_last)
                        if new_last == endWord:
                            min_level = level
                            result.append(new_paths)
                            break
                        else:
                            paths.append(new_paths)
        return result
                        
                
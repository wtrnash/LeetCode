"""

说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。
"""

# 用bfs
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList):
        d = {}
        result = {beginWord:1}
        q = []
        words = 'abcdefghijklmnopqrstuvwxyz'
        if not wordList:
            return 0
        
        for word in wordList:
            d[word] = 1
        
        q.append(beginWord)
        while q:
            now = q.pop(0)
            num = result[now]
            for i in range(0, len(now)):
                temp = now
                for c in words:
                    if temp[i] == c:
                        continue
                    else:
                        temp = temp[:i] + c + temp[i + 1:]
                    if temp in d:
                        if temp == endWord:
                            return num + 1
                        result[temp] = num + 1
                        q.append(temp)
                        d.pop(temp)
                
        return 0
                        
                        
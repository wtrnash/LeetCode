"""
设计一个支持以下两种操作的数据结构：

void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
说明:

你可以假设所有单词都是由小写字母 a-z 组成的。

"""

# 解答：使用字典树来做。遇到'.'时递归进行求解
class Node:
    def __init__(self):
        self.next = [None for x in range(26)]
        self.num = 0
        
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        p = self.root
        for i in word:
            if p.next[ord(i) - ord('a')] == None:
                p.next[ord(i) - ord('a')] = Node()
            p = p.next[ord(i) - ord('a')]
        p.num += 1
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        return self.dfs(word, self.root)
        
    def dfs(self, word, p):
        if p == None:
            return False
        
        if len(word) == 0:
            if p.num != 0:
                return True
            else:
                return False
        
        if word[0] != '.':
            return self.dfs(word[1:], p.next[ord(word[0]) - ord('a')])
        else:
            for i in range(26):
                if p.next[i] != None:
                    if self.dfs(word[1:], p.next[i]):
                        return True
            return False

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
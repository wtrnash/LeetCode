"""
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

输入: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]
说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:

你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。

"""
# 解答：前缀树+ dfs 使用前缀树来记录要搜索的单词做约束，这样就从o(n^3)变成了o(n^2)的复杂度，然后再dfs
class Node:
    
    def __init__(self):
        self.next = [None] * 26
        self.num = 0
        
class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = Node()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        p = self.root
        for i in word:
            if p.next[ord(i) - ord('a')] == None:
                p.next[ord(i) - ord('a')] = Node()
            p = p.next[ord(i) - ord('a')]
        
        p.num += 1
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        p = self.root
        for i in word:
            if p.next[ord(i) - ord('a')] == None:
                return False
            p = p.next[ord(i) - ord('a')]
        
        if p.num == 0:
            return False
        
        return True
        

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        p = self.root
        for i in prefix:
            if p.next[ord(i) - ord('a')] == None:
                return False
            p = p.next[ord(i) - ord('a')]
            
        return True
        


class Solution:
    def findWords(self, board, words):
        if len(board) == 0 or len(board[0]) == 0 or len(words) == 0:
            return []
        
        trie = Trie()
        for i in words:
            trie.insert(i)
        
        root = trie.root
        visited = [[False for x in range(len(board[0]))] for y in range(len(board))] 
        s = set()
        word = ""
        for i in range(len(board)):
            for j in range(len(board[0])):
                if root.next[ord(board[i][j]) - ord('a')]:
                    self.dfs(board, visited, i, j,  root.next[ord(board[i][j]) - ord('a')], s, word)
        
        return list(s)
    
    def dfs(self, board, visited, i, j, node, result, word):
        visited[i][j] = True
        word = word + board[i][j]
        if node.num != 0:
            result.add(word)
        
        if i < len(board) - 1  and not visited[i + 1][j] and node.next[ord(board[i + 1][j]) - ord('a')]:
            self.dfs(board, visited, i + 1, j, node.next[ord(board[i + 1][j]) - ord('a')], result, word[:])
        if i > 0 and not visited[i - 1][j] and node.next[ord(board[i - 1][j]) - ord('a')]:
            self.dfs(board, visited, i - 1, j, node.next[ord(board[i - 1][j]) - ord('a')], result, word[:])
        if j < len(board[0]) - 1 and not visited[i][j + 1] and node.next[ord(board[i][j + 1]) - ord('a')]:
            self.dfs(board, visited, i, j + 1, node.next[ord(board[i][j + 1]) - ord('a')], result, word[:])
        if j > 0 and not visited[i][j - 1] and node.next[ord(board[i][j - 1]) - ord('a')]:
            self.dfs(board, visited, i, j - 1, node.next[ord(board[i][j - 1]) - ord('a')], result, word[:])
        visited[i][j] = False
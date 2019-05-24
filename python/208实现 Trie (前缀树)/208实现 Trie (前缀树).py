"""
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。

"""

# 解答：26叉树，再用一个标记记录当前字符串的数量
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
        


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
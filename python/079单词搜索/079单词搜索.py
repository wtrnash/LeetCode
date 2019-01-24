"""
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.
"""

# 解答：利用dfs深搜做，先二重循环，找到和第一个字符一样的下标，然后再利用递归，在其的上下左右进行搜索即可
class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        self.m = len(board)
        if self.m == 0:
            return False
        self.n = len(board[0])
        if self.n == 0:
            return False
        self.k = len(word)
        if self.k == 0:
            return False
        is_used = [[False for i in range(self.n)] for j in range(self.m)]
        for i in range(self.m):
            for j in range(self.n):
                if board[i][j] == word[0]:
                    is_used[i][j] = True
                    if self.dfs(board, word, is_used, i, j, 1):
                        return True
                    is_used[i][j] = False
        
        return False
                    
    def dfs(self, board, word, is_used, x, y, pos):
        if pos == self.k:
            return True
        
        if x - 1 >= 0 and not is_used[x - 1][y] and board[x - 1][y] == word[pos]:
            is_used[x - 1][y] = True
            if self.dfs(board, word, is_used, x - 1, y, pos + 1):
                return True
            is_used[x - 1][y] = False
        if x + 1 < self.m and not is_used[x + 1][y] and board[x + 1][y] == word[pos]:
            is_used[x + 1][y] = True
            if self.dfs(board, word, is_used, x + 1, y, pos + 1):
                return True
            is_used[x + 1][y] = False
        if y - 1 >= 0 and not is_used[x][y - 1] and board[x][y - 1] == word[pos]:
            is_used[x][y - 1] = True
            if self.dfs(board, word, is_used, x, y - 1, pos + 1):
                return True
            is_used[x][y - 1] = False
        if y + 1 < self.n and not is_used[x][y + 1] and board[x][y + 1] == word[pos]:
            is_used[x][y + 1] = True
            if self.dfs(board, word, is_used, x, y + 1, pos + 1):
                return True
            is_used[x][y + 1] = False
        
        return False
    
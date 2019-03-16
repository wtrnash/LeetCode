"""
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
"""

# 解答：处理边界上的O,先改为*，然后找和它相连的O,全部改成*，这样剩下的O都是要变成X的，再把*的改为O即可
class Solution:
    def solve(self, board) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        self.m = len(board)
        if self.m == 0:
            return
        self.n = len(board[0])
        if self.n == 0:
            return
        
        for i in range(self.m):
            if board[i][0] == 'O':
                self.dfs(board, i, 0)
            
            if board[i][self.n - 1] == 'O':
                self.dfs(board, i, self.n - 1)
        
        for j in range(self.n):
            if board[0][j] == 'O':
                self.dfs(board, 0, j)
            
            if board[self.m - 1][j] == 'O':
                self.dfs(board, self.m - 1, j)
                
        
        for i in range(self.m):
            for j in range(self.n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                
                if board[i][j] == '*':
                    board[i][j] = 'O'
            
    def dfs(self, board, i, j):
        if i < 0 or i >= self.m or j < 0 or j >= self.n or board[i][j] != 'O':
            return
        
        board[i][j] = '*'
        self.dfs(board, i - 1, j)
        self.dfs(board, i + 1, j)
        self.dfs(board, i, j - 1)
        self.dfs(board, i, j + 1)
"""
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。
Note:

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。
"""

# 解答：用深搜，递归+回溯，暴力填满整个数独即可，每次选择能够填入当前格的数字进行深搜
class Solution:
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        self.dfs(board, 0, 0)
    
    def dfs(self, board, i, j):
        if i == 9:
            return True
        elif j == 9:
            return self.dfs(board, i + 1, 0)
        elif board[i][j] == '.':
            for k in self.getValidNum(board, i, j):
                board[i][j] = str(k)
                if self.dfs(board, i, j + 1):
                    return True
                
                board[i][j] = '.'
        else:
            return self.dfs(board, i, j + 1)
    
    # 返回当前格目前能填的数字
    def getValidNum(self, board, i, j):
        valid_num = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        for k in range(0, 9):
            if board[i][k] != '.':
                if int(board[i][k]) in valid_num:
                    valid_num.remove(int(board[i][k]))
        for k in range(0, 9):
            if board[k][j] != '.':
                 if int(board[k][j]) in valid_num:
                    valid_num.remove(int(board[k][j]))
        
        row = i // 3 * 3
        column = j // 3 * 3
        for k in range(row, row + 3):
            for l in range(column, column + 3):
                if board[k][l] != '.':
                    if int(board[k][l]) in valid_num:
                        valid_num.remove(int(board[k][l]))
        
        return valid_num
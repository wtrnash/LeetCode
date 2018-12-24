"""
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

上图为 8 皇后问题的一种解法。（图见leetcode)

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
"""
# 用递归做，每次处理一排，判断列的位置是否合法
class Solution:
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        result = []
        pos = [-1] * n
        self.dfs(result, pos, 0)
        return result
    
    def dfs(self, result, pos, row):
        n = len(pos)
        if row == n:
            temp = []
            for i in range(n):
                column = ''
                for j in range(n):
                    if not j == pos[i]:
                        column = column + '.'
                    else:
                        column = column + 'Q'
                temp.append(column[:]) 
            
            result.append(temp[:])
            return
        
        for i in range(n):
            if self.isValid(pos, row, i):
                pos[row] = i
                self.dfs(result, pos[:], row + 1)
                
            
    def isValid(selfr, pos, row, column):
        for i in range(row):
            if pos[i] == column or abs(row - i) == abs(pos[i] - column):
                return False
        
        return True
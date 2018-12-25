"""
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。(图见leetcode)

给定一个整数 n，返回 n 皇后不同的解决方案的数量。

示例:

输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]

"""

# 解答：和051一样的思路，递归，每次处理一行中的合法位置，只是最后的输出变成了整型的累加
class Solution:
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        pos = [-1] * n
        return self.dfs(pos, 0)
    
    def dfs(self, pos, row):
        result = 0
        n = len(pos)
        if row == n:
            return 1
        
        for i in range(n):
            if self.isValid(pos, row, i):
                pos[row] = i
                result = result + self.dfs(pos, row +1)
        
        return result
        
        
    
    def isValid(self, pos, row, column):
        for i in range(row):
            if column == pos[i] or abs(row - i) == abs(pos[i] - column):
                return False
        return True
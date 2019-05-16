"""
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3
"""
# 解答：dfs做，碰到1的结果+1然后进行dfs，把相连的1都设为0
class Solution:
    def numIslands(self, grid) -> int:
        if len(grid) == 0:
            return 0
        if len(grid[0]) == 0:
            return 0
        result = 0
        for i in range(0, len(grid)):
            for j in range(0, len(grid[0])):
                if grid[i][j] == '1':
                    result += 1
                    self.dfs(grid, i, j)
        
        return result
    def dfs(self, grid, x, y):
        if x < 0 or x >= len(grid) or y < 0 or y >= len(grid[0]) or grid[x][y] == '0':
            return
        
        grid[x][y] = '0'
        self.dfs(grid, x - 1, y)
        self.dfs(grid, x + 1, y)
        self.dfs(grid, x, y - 1)
        self.dfs(grid, x, y + 1)
        
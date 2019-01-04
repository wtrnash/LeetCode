"""
给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
"""
# 解答：初始化矩阵后，按螺旋的顺序依次赋值即可。类似螺旋矩阵I
class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        matrix = [[0 for col in range(n)] for row in range(n)]
        num = 1
        round = 0
        while num <= n * n:
            for j in range(round, n - round):
                matrix[round][j] = num
                num = num + 1
            
            for j in range(round + 1, n - round):
                matrix[j][n - round - 1] = num
                num = num + 1
            
            for j in range(n - round - 2, round - 1, -1):
                matrix[n - round - 1][j] = num
                num = num + 1
            
            for j in range(n - round - 2, round, -1):
                matrix[j][round] = num
                num = num + 1
            
            round = round + 1
        
        return matrix
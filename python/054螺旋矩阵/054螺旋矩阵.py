"""
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
"""

# 解答：就按照螺旋的方式，记录行的开始和结束以及列的开始和结束，每次依照先从开始行的开始列到结束列，开始行+1，再从结束列的开始行到结束行，结束列-1，再从结束行的结束列到开始列
# 结束行+1，再从开始列的结束行到开始行，开始列+1。依次进行，每次判断是否越界
class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        result = []
        if len(matrix) == 0:
            return result
        
        start_row = 0
        end_row = len(matrix) - 1
        start_column = 0
        end_column = len(matrix[0]) - 1
        while start_row <= end_row and start_column <= end_column:
            for i in range(start_column, end_column + 1):
                result.append(matrix[start_row][i])
            
            start_row = start_row + 1
            if start_row > end_row:
                break
            
            for i in range(start_row, end_row + 1):
                result.append(matrix[i][end_column])
            
            end_column = end_column - 1
            if start_column > end_column:
                break
            
            for i in range(end_column, start_column - 1, -1):
                result.append(matrix[end_row][i])
                
            end_row = end_row - 1
            
            for i in range(end_row, start_row - 1, -1):
                result.append(matrix[i][start_column])
            
            start_column = start_column + 1
            
        return result
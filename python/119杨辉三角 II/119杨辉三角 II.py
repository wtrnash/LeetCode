"""
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？
"""

# 解答：类似118,，只是把最后一行输出。然后这里从第0行开始，用一行来处理，每次从每行最后一个开始加
class Solution:
    def getRow(self, rowIndex: int):
        result = [0 for i in range(1 + rowIndex)]
        result[0] = 1
        for i in range(1, rowIndex + 1):
            for j in range(i, 0, -1):
                result[j] += result[j - 1]
                
        
        return result
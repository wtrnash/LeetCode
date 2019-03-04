"""
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

"""

# 解答：二重循环，利用之前上一层的值得到下一层的值
class Solution:
    def generate(self, numRows: int):
        result = []
        if numRows == 0:
            return result
        
        result.append([1])
        if numRows == 1:
            return result
        
        result.append([1, 1])
        
        for i in range(3, numRows + 1):
            temp = []
            for j in range(i):
                if j == 0 or j == i - 1:
                    temp.append(1)
                else:
                    temp.append(result[i - 2][j - 1] + result[i - 2][j])
            
            result.append(temp)
            
        
        return result
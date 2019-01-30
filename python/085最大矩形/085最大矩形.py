"""
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:

输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6
"""

# 解答：利用84题的知识，这题相当于是多层的求柱状图中的最大矩形。每次从第一层开始求矩形，然后逐层累加。要注意的是遇到0，该列的高度直接清0
class Solution:
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        n = len(matrix)
        if n == 0:
            return 0
        m = len(matrix[0])
        if m == 0:
            return 0
        
        heights = [0] * m
        result = 0
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == '0':
                    heights[j] = 0
                else:
                    heights[j] += 1
            result = max(result, self.largestRectangleArea(heights))
            
        return result
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        heights.append(0)
        i = 0
        st = []
        max_area = 0
        while i < len(heights):
            if len(st) == 0 or heights[st[-1]] <= heights[i]:
                st.append(i)
                i += 1
            else:
                temp = st.pop()
                if len(st) == 0:
                    length = i
                else:
                    length = i - st[-1] - 1
                max_area = max(max_area, length * heights[temp])
        
        return max_area
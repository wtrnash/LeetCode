"""
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 
（图见leetcode)


以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

 
（图见leetcode)


图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

 

示例:

输入: [2,1,5,6,2,3]
输出: 10
"""
# 解答：利用递增栈，这样弹出时可以保证该元素是从右往左里高度最小的元素，从而可以正确计算面积
class Solution:
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
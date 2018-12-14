"""
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
* 图见Leetcode网址

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
"""

# 解答： 从左、右分别往中间遍历，实时记录左边最高的和右边最高的，雨水取决于较短的一边，所以当某一边较短时，记录当前高度和某一边较短的高度差，即为当前的雨水面积
class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if len(height) < 3:
            return 0
        left = 0
        right = len(height) - 1
        leftMax = height[0]
        rightMax = height[right]
        area = 0
        while left <= right:
            if height[left] > leftMax:
                leftMax = height[left]
            if height[right] > rightMax:
                rightMax = height[right]
            
            if leftMax <= rightMax:
                area = area  + leftMax - height[left]
                left = left + 1
            else:
                area = area  + rightMax - height[right]
                right = right - 1
        
        return area
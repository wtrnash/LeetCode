"""
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
"""

# 解答 先以首尾作为起始和结束的面积为基准，此时移动长的那根，由于面积受到短的限制且宽变短，所以面积一定不会增加
# 所以只有移动短的那根，才会在一开始面积的基础上可能面积会增大
# 以此类推，一直到首碰上尾为止，时间复杂度O(n)

class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        j = len(height) - 1
        i = 0
        result = 0
        while i < j:
            if height[i] > height[j]:
                current = (j - i) * height[j]
                j = j - 1
            else:
                current = (j - i) * height[i]
                i = i + 1
            
            if result < current:
                result = current
        return result
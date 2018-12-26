"""
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
"""
# 解答：用分治做，注意处理跨越中间的一段
class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        return self.divide(nums, 0, len(nums) - 1)
    
    def divide(self, nums, left, right):
        if left == right:
                return nums[left]

        center = (left + right) // 2
        leftMax = self.divide(nums, left, center)
        rightMax = self.divide(nums, center + 1, right)
        
        leftCenter = nums[center]
        temp = 0
        for i in range(center, left - 1, -1):
            temp = temp + nums[i]
            if temp > leftCenter:
                leftCenter = temp
        
        rightCenter = nums[center + 1]
        temp = 0
        for i in range(center + 1, right + 1):
            temp = temp + nums[i]
            if temp > rightCenter:
                rightCenter = temp
        
        return max(leftMax, rightMax, leftCenter + rightCenter)
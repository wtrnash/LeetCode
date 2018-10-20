"""
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
"""

# 解答：和015三数之和类似的套路，遍历第一个数，后面两个数首尾相加，往中间靠，用一个变量记录最接近的三个数之和 

class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        result = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)):
            temp = target - nums[i]
            left = i + 1
            right = len(nums) - 1
            while left < right:
                if nums[left] + nums[right] == temp:
                    return nums[i] + nums[left] + nums[right]
                elif nums[left] + nums[right] < temp:
                    if abs(temp - nums[left] - nums[right]) < abs(result - target):
                        result = nums[i] + nums[left] + nums[right]
                    left = left + 1
                else:
                    if abs(temp - nums[left] - nums[right]) < abs(result - target):
                        result = nums[i] + nums[left] + nums[right]
                    right = right - 1
        
        return result
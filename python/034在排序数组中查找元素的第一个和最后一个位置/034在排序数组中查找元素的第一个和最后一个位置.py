"""
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
"""

# 解答：用二分搜索，然后比较相邻的元素确定首尾位置
class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) == 0:
            return [-1, -1]
        
        result = []
        low = 0
        high = len(nums) - 1
        start = -1
        end = -1
        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == target:
                start = end = mid
                while start - 1 >= 0 and nums[start - 1] == target:
                    start = start - 1
                while end + 1 < len(nums) and nums[end + 1] == target:
                    end = end + 1
                break
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1
        
        return [start, end]
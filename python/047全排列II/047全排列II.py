"""
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
"""

# 解答：类似046题，主要需要去重，所以每次交换，对于同样的数字，只交换一次，所以需要判断前面有没有相同的，有则不做交换
class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        self.dfs(result, nums, 0)
        return result
    
    def dfs(self, result, nums, start):
        if start >= len(nums) - 1:
            result.append(nums[:])
            return
        
        for i in range(start, len(nums)):
            if self.needSwap(nums, start, i):
                nums[start], nums[i] = nums[i], nums[start]
                self.dfs(result, nums, start + 1)
                nums[start], nums[i] = nums[i], nums[start]
        
    def needSwap(self, nums, start, end):
        for i in range(start, end):
            if nums[i] == nums[end]:
                return False
        return True
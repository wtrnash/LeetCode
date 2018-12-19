"""
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
"""
# 解答：用递归进行，每次交换两个元素，使得能返回所有的全排列
class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        self.perm(result, nums, 0, len(nums) - 1)
        return result
    
    def perm(self, result, nums, begin, end):
        if begin >= end:
            result.append(nums[:])
            return
        
        for i in range(begin, end + 1):
            nums[begin], nums[i] = nums[i], nums[begin]
            self.perm(result, nums, begin + 1, end)
            nums[begin], nums[i] = nums[i], nums[begin]
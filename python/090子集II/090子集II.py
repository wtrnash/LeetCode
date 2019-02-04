"""
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
"""
# 解答：dfs做，可以先排序，然后当前元素和上一个相同时不加入当前元素数组来防止重复
class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = [[]]
        temp = []
        nums.sort()
        self.dfs(nums, result, temp, 0)
        return result
    
    def dfs(self, nums, result, temp, start):
        if start == len(nums):
            return
        
        for i in range(start, len(nums)):
            if i > start and nums[i] == nums[i - 1]:
                continue
            
            temp.append(nums[i])
            result.append(temp[:])
            self.dfs(nums, result, temp, i + 1)
            temp.pop()
            
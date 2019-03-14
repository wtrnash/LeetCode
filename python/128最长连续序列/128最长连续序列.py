"""
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

"""

# 解答：不用排序，用字典来做，边界值记录当前序列的长度，这样碰见没有见过的值，左右两边如果有就一定是边界值，就可以加上当前值来进行更新
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        max_count = 0
        d = {}
        for i in range(0, len(nums)):
            if nums[i] in d.keys():
                continue
            
            left = 0
            right = 0
            if nums[i] - 1 in d.keys():
                left = d[nums[i] - 1]
            
            if nums[i] + 1 in d.keys():
                right = d[nums[i] + 1]
            
            count = 1 + left + right
            d[nums[i]] = count
            if nums[i] - 1 in d.keys():
                d[nums[i] - left] = count
                
            if nums[i] + 1 in d.keys():
                d[nums[i] + right] = count
            
            if count > max_count:
                max_count = count
        return max_count
            
            
        
        

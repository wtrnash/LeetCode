"""
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
"""

# 由于时间复杂度为O（n)，不能用排序。所以采用原地交换的方式，让数组第i个位置存放的数为i+1。这样再遍历一遍时返回不存放i+1的那个位置i即可
class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 1
        i = 0
        while i < len(nums):
            if nums[i] - 1 >= 0 and nums[i] - 1 < len(nums) and nums[i] != nums[nums[i] - 1]:
                a = nums[i] - 1
                
                temp = nums[i]
                nums[i] = nums[nums[i] - 1] 
                nums[a]  = temp
            else:
                i = i + 1
        
        for i in range(len(nums)):
            if nums[i] - 1 != i:
                return i + 1
            
        return len(nums)  + 1
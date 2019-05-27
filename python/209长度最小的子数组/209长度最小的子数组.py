"""
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

"""

# 解答：双指针法，进行滑动窗口 用start,end来表示连续的子串下标。如果加上当前end比s小，则end++。否则记录当前result，然后start++。
class Solution:
    def minSubArrayLen(self, s: int, nums) -> int:
        start = 0
        end = 0
        n = len(nums)
        temp = 0
        result = 2 ** 31 - 1
        for end in range(n):
            if nums[end] >= s:
                return 1
            temp += nums[end]
            while temp >= s:
                result = min(result, end - start + 1)
                temp -= nums[start]
                start += 1
        
        if result == 2 ** 31 - 1:
            return 0
        return result
            
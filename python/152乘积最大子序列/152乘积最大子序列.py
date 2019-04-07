"""
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

"""

# 解答：记录最小和最大的数字，如果来的是负数，则交换两者，比较当前的和当前的乘以最小或最大的小或大，记录最大值。
class Solution:
    def maxProduct(self, nums) -> int:
        if len(nums) == 0:
            return 0
        
        result = min_num = max_num = nums[0]
        for i in range(1, len(nums)):
            if nums[i] < 0:
                temp = max_num
                max_num = max(min_num * nums[i], nums[i])
                min_num = min(temp * nums[i], nums[i])
            else:
                max_num = max(max_num * nums[i], nums[i])
                min_num = min(min_num * nums[i], nums[i])
                
            result = max(result, max_num)
        return result
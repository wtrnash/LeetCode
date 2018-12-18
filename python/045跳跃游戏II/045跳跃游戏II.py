"""
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。
"""
#  解答： 用贪心算法，算出每步能覆盖的最大范围即可
class Solution:
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        last = 0    # 上一步能覆盖的最远范围
        current = 0 # 当前能覆盖的最远范围
        result = 0  # 跳的次数
        for i in range(len(nums)):
            if i > last:    # i 比上一步覆盖的最远范围大了则更新last以及跳的次数
                last = current
                result = result + 1
            current = max(current, i + nums[i])     # 实时更新当前能跳的最远范围
        
        return result
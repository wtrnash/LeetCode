"""
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
"""

# 解答： 类似三数之和的做法，排序后排除不可能的情况为了加快速度，然后二重循环，并用首尾指针来找到适合的数，还要排除重复的情况
class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        nums.sort()
        # 没有四个元素直接返回结果
        if len(nums) < 4:
            return result
        # 最小和比目标大以及最大和比目标小的情况
        if nums[0] + nums[1] + nums[2] + nums[3] > target or nums[len(nums) - 1] + nums[len(nums) - 2] + nums[len(nums) - 3] + nums[len(nums) - 4] < target:
            return result
        
        for i in range(len(nums)):
            # 排除重复
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            for j in range(i + 1, len(nums)):
                # 排除重复
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                
                # 首尾往中间靠
                left = j + 1
                right = len(nums) - 1
                while left < right:
                    if nums[i] + nums[j] + nums[left] + nums[right] == target:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        left = left + 1
                        right = right - 1
                        while left < right and nums[left] == nums[left - 1] and nums[right] == nums[right + 1]:
                            left = left + 1
                            right = right - 1
                    elif nums[i] + nums[j] + nums[left] + nums[right] < target:
                        left = left + 1
                    else:
                        right = right - 1
        
        return result
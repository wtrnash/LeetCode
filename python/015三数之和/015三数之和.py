"""
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
"""

# 解答，先排序，确定第一个数，然后 后面两个数加起来应该是第一个数取负，后面两个数一个从前往后，一个从后往前不断进行求和即可
# 如果和较大，则后面一个数往前，如果和较小，则前面一个数往后，如果相等则加入结果
class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        nums.sort() # 先排序
        for i in range(len(nums)):
            if nums[i] > 0:     # 正数直接跳出，因为排序后如果该数为正数，一定不能和后面两个比它大的数组成和为0
                break
            if i > 0 and nums[i - 1] == nums[i]:      # 如果和前面那个数一样则越过该数，排除重复的情况
                continue
            number = -nums[i]
            left = i + 1
            right = len(nums) - 1
            while left < right:
                if nums[left] + nums[right] == number:
                    result.append([nums[i], nums[left], nums[right]])
                    left = left + 1
                    right = right - 1
                    while left < right and nums[left] == nums[left - 1] and nums[right] == nums[right + 1]:    # 排除重复
                        left = left + 1
                        right = right - 1
                elif nums[left] + nums[right] < number: 
                    left = left + 1
                else:
                    right = right - 1
            
        return result
                    
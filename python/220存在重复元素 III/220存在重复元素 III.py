"""
给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false

"""

# 解答：利用set，存储最近的k个元素的值来判断。 对t=0做特殊处理判断集合中是否有该元素即可
class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k: int, t: int) -> bool:
        if len(nums) <= 1:
            return False
        
        s = set()
        for i in range(len(nums)):
            if t == 0:
                if nums[i] in s:
                    return True
            else:
                for j in s:
                    if abs(nums[i] - j) <= t:
                        return True
            
            s.add(nums[i])
            if len(s) > k:
                s.remove(nums[i - k])
        
        return False

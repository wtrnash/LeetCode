"""
给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

示例 1:

输入: [3,2,3]
输出: [3]
示例 2:

输入: [1,1,1,3,3,2,2,2]
输出: [1,2]

"""

# 大于n/3最多2个数，找到这两个数即可。类似求众数找一个数的方法。
class Solution:
    def majorityElement(self, nums):
        x = 0
        y = 0
        count_x = 0
        count_y = 0
        for num in nums:
            if (count_x == 0 or x == num) and y != num:
                x = num
                count_x += 1
            elif count_y == 0 or y == num:
                y = num
                count_y += 1
            else:
                count_x -= 1
                count_y -= 1
                
        result = []
        c1 = 0
        for num in nums:
            if x == num:
                c1 += 1
        
        if c1 > len(nums) // 3:
            result.append(x)
            
        c2 = 0
        for num in nums:
            if y == num:
                c2 += 1
        
        if c2 > len(nums) // 3 and x != y:
            result.append(y)
        
        return result
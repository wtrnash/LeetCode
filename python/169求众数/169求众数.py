"""
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

"""

# 解答：遍历一遍，计数，遇到相同的数+1，不同的数-1，遇到0重新换个数开始计，最后留下的一定是最多的数

class Solution:
    def majorityElement(self, nums) -> int:
        count = 0
        for i in nums:
            if count == 0:
                result = i
                count = 1
            else:
                if i == result:
                    count += 1
                else:
                    count -= 1
        
        return result
            
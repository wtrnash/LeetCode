"""

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4
"""

# 解答：用异或做，相同的数异或为0,0和任何数异或为任何数本身，所以可以通过0与数组所有数不断异或得到结果。
class Solution:
    def singleNumber(self, nums) -> int:
        n = len(nums)
        if n == 1:
            return nums[n - 1]
        
        result = 0
        for i in range(n):
            result = result ^ nums[i]
        
        return result
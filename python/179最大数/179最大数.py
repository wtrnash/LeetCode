"""
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
"""
# 解答：冒泡排序，比较a+b和b+a的大小即可
class Solution:
    def largestNumber(self, nums) -> str:
        for i in range(0, len(nums)):
            for j in range(1, len(nums) - i):
                if nums[j] == nums[j - 1]:
                    continue
                a = str(nums[j - 1]) + str(nums[j])
                b = str(nums[j]) + str(nums[j - 1])
                if a < b:
                    nums[j - 1], nums[j] = nums[j], nums[j - 1]
            
                
        if nums[0] == 0:
            return "0"
        
        result = []
        for i in nums:
            result.append(str(i))
        
        return "".join(result)
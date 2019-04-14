"""
给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

如果数组元素个数小于 2，则返回 0。

示例 1:

输入: [3,6,9,1]
输出: 3
解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
示例 2:

输入: [10]
输出: 0
解释: 数组元素个数小于 2，因此返回 0。
说明:

你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。

"""

# 解答：桶排序
class Solution:
    def maximumGap(self, nums) -> int:
        n = len(nums)
        if n < 2:
            return 0
        
        max_num = max(nums)
        min_num = min(nums)
        size = max(1, (max_num - min_num) // (n - 1))
        bucket_num = (max_num - min_num)  // size + 1
        min_bucket = [max_num + 1 for x in range(bucket_num)]
        max_bucket = [min_num - 1 for x in range(bucket_num)]
        for num in nums:
            idx = (num - min_num) // size
            min_bucket[idx] = min(num, min_bucket[idx])
            max_bucket[idx] = max(num, max_bucket[idx])
            
        result = 0
        i = 0
        while i < bucket_num:
            if max_bucket[i] == min_num - 1:
                i += 1
                continue
            
            j = i + 1
            if j >= bucket_num:
                break
            
            while min_bucket[j] == max_num + 1:
                j += 1
                
            result = max(result, min_bucket[j] - max_bucket[i])
            i += 1
        
        
        return result
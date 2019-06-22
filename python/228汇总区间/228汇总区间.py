"""
给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

示例 1:

输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
示例 2:

输入: [0,2,3,4,6,8,9]
输出: ["0","2->4","6","8->9"]
解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。
"""
# 解答：遍历一遍，比较和前一个元素是否是连续即可，注意处理首尾
class Solution:
    def summaryRanges(self, nums):
        if not nums:
            return []
        result = []
        for i in range(len(nums)):
            if i == 0:
                start = nums[0]
                end = nums[0]
            else:
                if nums[i] == nums[i - 1] + 1:
                    end = nums[i]
                else:
                    if start == end:
                        result.append(str(start))
                    else:
                        result.append(str(start) + "->" + str(end))
                    start = nums[i]
                    end = nums[i]
        if start == end:
            result.append(str(start))
        else:
            result.append(str(start) + "->" + str(end))
        return result
                
                
                        
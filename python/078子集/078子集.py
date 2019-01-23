"""
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
"""
# 解答：可以用位运算来做。n个元素的子集个数为2^n, 外层遍历2^n次。每次右移n次，与1进行位于，相当于判断第一层遍历的索引i的n位中有几位是1，对应位数是1的将位数对应
# 的下标的元素放入当前数组即可。实质是2进制数可以完美的表达n个元素有2^n个子集。有每位是否是1来表示是否加入数组

class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        for i in range(0, 2 ** len(nums)):      # n个元素有2^n个子集
            index = i
            temp = []
            for j in range(0, len(nums)):       # 每个index有n位。比如{1,2,3}求子集，那么000相当于空集，001相当于{1}，010相当于{2}，111相当于{1,2,3}
                if index >> j & 1:              # 每次进行右移和与1进行位于，相当于判断哪一位是否是1
                    temp.append(nums[j])
            
            result.append(temp)
        
        return result
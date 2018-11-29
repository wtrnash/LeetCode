"""
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
"""

# 解答： 首先从最后一个元素开始往前遍历，每一个元素再从后往前直到自己为止和后面的元素进行比较，如果当前元素小于遍历到的某个元素（此元素同时为后面元素的最小元素），即和其交换，
# 然后把当前遍历元素后面的元素进行升序排序
# 如果已经是降序，最后再进行逆序即可
class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if len(nums) <= 1:
            return
        i = len(nums) - 1
        while i >= 0:
            j = len(nums) - 1
            while i < j:
                if nums[i] < nums[j]:
                    nums[i], nums[j] = nums[j], nums[i]
                    nums[i + 1 :] = sorted(nums[i + 1 :])
                    return
                j = j - 1
            
            i = i - 1
        
        nums.sort()
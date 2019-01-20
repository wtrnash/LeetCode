"""
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？
"""
# 解答：使用一趟扫描。用zero记录0之后的下一个下标，用two记录2之前的一个下标。遇到0，就和zero交换，然后i++；遇到2，则和two交换，因为不知道是1还是0，所以i不加；遇到1则直接i++
# 一直遍历到two为止即可
class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        zero = 0
        two = len(nums)
        i = 0
        while i < two:
            if nums[i] == 0:
                nums[i], nums[zero] = nums[zero], nums[i]
                i = i + 1
                zero = zero + 1
            elif nums[i] == 2:
                two = two - 1
                nums[i], nums[two] = nums[two], nums[i]
            else:
                i = i + 1
            
"""
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
"""

# 解答：用num2的元素依次和nums1的去比较，如果小于，则说明要将nums2的元素添加在nums1之前，将nums1的元素都往后移一位，m++；
# 如果大于，先判断nums1有没遍历完，如果遍历完直接在后面加即可。没有遍历完则nums1往后遍历一位
# 一直遍历完nums2为止
class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        i = 0
        j = 0
        while j < n:
            if nums2[j] < nums1[i]:
                for k in range(m, i, -1):
                    nums1[k] = nums1[k - 1]
                nums1[i] = nums2[j]
                m += 1
                j += 1
                i += 1
            else:
                if i >= m:
                    nums1[i] = nums2[j]
                    i += 1
                    j += 1
                else:
                    i += 1
        
        
                
"""
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"
示例 2:

输入: n = 4, k = 9
输出: "2314"
"""

# 可以不用列出每一个排列，直接推出第k个排列。因为每个位置上每个数字出现的次数是一样的，所以可以根据k先确定第一个位置上的数字。
# 具体就是 (k - 1) / (n - 1)!。 比如n为4，那么第一个位置上每个数字出现的次数就是3！，就是6次， 如果要求k为12， （12 - 1) / 6 就是1
# 所以第一个数字的下标为1，实际上就是数字2. 第二位可以根据k对(n - 1)!取余后更新k，然后按照第一步继续做，即可。
class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        nums = [i for i in range(1, n + 1)]
        f = [1]
        for i in range(1, n + 1):
            f.append(f[i - 1] * nums[i - 1])

        result = []
        for i in range(n, 0, -1):
            j = (k - 1) // f[i - 1]
            k = k % f[i - 1]
            result.append(str(nums[j]))
            nums.remove(nums[j])

        return "".join(result)
"""
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

"""

# 解答：使用递归完成即可。给定一个当前元素，每次只能添加当前元素以及其之后的元素。每次递归k-1，直到k等于0为止。
class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        self.result = []
        temp = []
        self.add(n, k, 1, temp)
        return self.result
        
    def add(self, n, k, now, temp):
        if k == 0:
            self.result.append(temp[:])
            return
        
        for i in range(now, n + 1):
            temp.append(i)
            self.add(n, k - 1, i + 1, temp)
            temp.pop()
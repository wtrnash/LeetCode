"""
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
"""

# 解答：直接用乘法会超时。所以用递归进行二分，把每次的n分成n/2的相乘形式，奇数就多乘一个x
class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1
        if n == 1:
            return x
        if n < 0:
            return 1 / self.pow(x, -n)  # 处理负数
        else:
            return self.pow(x, n)
        
    
    def pow(self, x, n):
        if n == 1:
            return x
        half = self.pow(x, n // 2)
        if n % 2 == 0:
            return half * half
        else:
            return x * half * half
        
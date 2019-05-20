"""
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
"""

# 解答：厄多拉塞筛法，找到第一个质数，其倍数全设为false，以此类推即可
class Solution:
    def countPrimes(self, n: int) -> int:
        count = 0
        if n < 2:
            return count
        
        is_prime = [True] * n
        for i in range(2, n):
            if is_prime[i]:
                for j in range(i * i, n, i):
                    is_prime[j] = False
        
        for i in range(2, n):
            if is_prime[i]:
                count += 1
                
        return count
        
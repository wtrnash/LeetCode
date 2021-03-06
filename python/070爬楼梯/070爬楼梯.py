"""
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
"""

# 解答：最简单的动态规划题，能到当前楼的方法等于当前楼前两层的方法之和


class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0] * n
        dp[0] = 1
        if n > 1:
            dp[1] = 2
        for i in range(2, n):
            dp[i] = dp[i - 1] + dp[i - 2]
        
        return dp[n - 1]
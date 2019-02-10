"""
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""

# 解答：用卡特兰数做。比如1为节点的dp[1]，其左右子树都是dp[0]，所以dp[1] = dp[0] * dp[1 - 1] = 1 * 1 =1
# 节点1,2时，以1做根节点，左子树为dp[0]，右子树只有一个2，为dp[1];以2为根节点，左子树为1 dp[1]，右子树为空，dp[0]
# dp[2] = dp[0] * dp[2-1] + dp[1] * dp[2- 2]
# 符合卡特兰数公式 dp[n] = dp[0] * dp[n - 1] + dp[1] * dp[n - 2] + …… + dp[n - 1] * dp[0]
# 然后用动态规划求出所有值，返回dp[n]即可
class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0] * (n + 1)
        dp[0] = 1
        if n == 0:
            return 0
        
        for i in range(1, n + 1):
            for j in range(0, i):
                dp[i] += dp[j] * dp[i - j - 1]
        
        return dp[n]
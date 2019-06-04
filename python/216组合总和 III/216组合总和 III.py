"""
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

"""

# 解答：dfs做
class Solution:
    def combinationSum3(self, k: int, n: int):
        result = []
        temp = []
        self.dfs(result, temp, k, n, 1)
        return result
    
    def dfs(self, result, temp, k, n, pos):
        if len(temp) > k:
            return
        if n < 0:
            return
        if n == 0:
            if len(temp) == k:
                result.append(temp[:])
            return
        
        for i in range(pos, 10):
            temp.append(i)
            self.dfs(result, temp, k, n - i, i + 1)
            temp.pop()
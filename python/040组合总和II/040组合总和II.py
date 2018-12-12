"""
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
"""
# 解答：相比39题，这题主要是每个元素只能用一次，所以递归的时候start设置要加1。另外还要考虑有相同的元素导致结果重复的问题。
class Solution:
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        result = []
        temp = []
        candidates.sort()
        self.dfs(result, temp, candidates, target, 0)
        return result
    
    def dfs(self, result, temp, candidates, target, start):
        if target < 0:
            return
        elif target == 0:
            result.append(temp[:])
            return
        n = len(candidates)
        for i in range(start, n):
            if i > start and candidates[i] == candidates[i - 1]:
                continue
            
            temp.append(candidates[i])
            self.dfs(result, temp, candidates, target - candidates[i], i + 1)
            temp.pop()
            
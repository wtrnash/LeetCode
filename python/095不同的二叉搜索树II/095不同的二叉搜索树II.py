"""
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""
# 解答：利用递归，分别求得左右子树可能的情况，然后分别组合
# Definition for a binary tree node.
class TreeNode:
         def __init__(self, x):
            self.val = x
            self.left = None
            self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        result = []
        if n == 0:
            return result
        
        result = self.recursion(1, n)
        return result
    
    def recursion(self, begin, end):
        result = []
        if begin > end:
            result.append(None)
            return result
        
        for i in range(begin, end + 1):
            left = self.recursion(begin, i - 1)
            right = self.recursion(i + 1, end)
            
            for j in left:
                for k in right:
                    root = TreeNode(i)
                    root.left = j
                    root.right = k
                    result.append(root)
                    
        
        return result
        
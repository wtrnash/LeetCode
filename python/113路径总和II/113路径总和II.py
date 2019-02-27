"""
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
"""
# 解答：类似112，递归即可，记录途径的节点
# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None


class Solution:
    def pathSum(self, root: TreeNode, sum: int):
        result = []
        temp = []
        self.recursion(root, result, temp, sum)
        return result
    
    def recursion(self, root, result, temp, sum):
        if root == None:
            return
        
        sum -= root.val
        
        temp.append(root.val)
        if root.left == None and root.right == None and sum == 0:
            result.append(temp[:])
            return 
        
        self.recursion(root.left, result, temp[:], sum)
        self.recursion(root.right, result, temp[:], sum)
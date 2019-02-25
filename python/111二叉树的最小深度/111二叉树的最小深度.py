"""
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.

"""
# 解答：递归求深度。按当前为空、子树为空、其中一个子树为空以及普通情况来判断
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: 'TreeNode') -> 'int':
        if not root:
            return 0
        
        left = self.minDepth(root.left)
        right = self.minDepth(root.right)
        if root.left and root.right:
            return 1 + min(left, right)
        else:
            return 1 + left + right
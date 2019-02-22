"""
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
"""
# 解答：利用递归，每次取最中间的值，用类似二分的方式来构建BST
# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: 'List[int]') -> 'TreeNode':
        return self.buildTree(nums, 0, len(nums) - 1)
    
    
    def buildTree(self, nums, l, r):
        if l > r:
            return None
        
        mid = (l + r) // 2
        root = TreeNode(nums[mid])
        root.left = self.buildTree(nums, l, mid - 1)
        root.right = self.buildTree(nums, mid + 1, r)
        
        return root
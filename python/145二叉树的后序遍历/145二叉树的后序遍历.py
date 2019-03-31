"""
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
"""
# 非递归实现
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root):
        if root == None:
            return []
        result = []
        stack = []
        stack.append(root)
        while stack:
            root = stack.pop()
            result.insert(0, root.val)
            if root.left:
                stack.append(root.left)
            
            if root.right:
                stack.append(root.right)
            
        return result
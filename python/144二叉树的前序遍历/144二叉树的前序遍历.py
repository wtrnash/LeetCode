"""
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

"""
# 解答：非递归做
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root):
        result = []
        stack = []
        while root or stack:
            if root:
                result.append(root.val)
                stack.append(root)
                root = root.left
            else:
                temp = stack.pop()
                root = temp.right
        return result
        
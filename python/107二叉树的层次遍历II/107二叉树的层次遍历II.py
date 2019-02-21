"""
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]
"""
# 解答：类似102，将最后的结果逆序即可
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: 'TreeNode') -> 'List[List[int]]':
        queue = []
        result = []
        if not root:
            return result
        
        queue.append(root)
        while not len(queue) == 0:
            count = len(queue)
            temp = []
            while count > 0:
                t = queue.pop(0)
                if t.left:
                    queue.append(t.left)
                if t.right:
                    queue.append(t.right)
                
                temp.append(t.val)
                count -= 1
            result.append(temp[:])
        
        return result[::-1]
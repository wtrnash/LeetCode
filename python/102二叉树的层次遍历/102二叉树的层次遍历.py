"""
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
"""

# 解答：利用队列实现层序遍历，并用count进行计数
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
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
        
        return result
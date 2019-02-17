"""
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
"""

# 解答：和102类似，就是需要用一个序号来判断该层需不需要逆序
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        queue = []
        result = []
        if not root:
            return result
        
        queue.append(root)
        need_reverse = False
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
            if not need_reverse:
                result.append(temp[:])
            else:
                result.append(temp[::-1])
            
            need_reverse = not need_reverse
        
        return result
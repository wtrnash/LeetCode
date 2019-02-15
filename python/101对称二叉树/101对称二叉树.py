"""
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
"""

# 解答：利用队列进行迭代做。将左右子树分别放入两个队列，判空判等，然后再将左右子树和右左子树分别放入两个队列
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        
        q1 = [root.left]
        q2 = [root.right]
        while not len(q1) == 0 and not len(q2) == 0:
            temp1 = q1.pop(0)
            temp2 = q2.pop(0)
            if not temp1 and not temp2:
                continue
            elif not temp1 or not temp2:
                return False
            elif temp1.val == temp2.val:
                q1.append(temp1.left)
                q1.append(temp1.right)
                q2.append(temp2.right)
                q2.append(temp2.left)
            else:
                return False
        
        return True
            
            
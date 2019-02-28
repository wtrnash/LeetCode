"""
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
"""

# 解答：用非递归的方式，找到根节点的左子树的最右节点，将根节点的右子树赋给它，然后将根节点的左子树赋给根节点的右子树，左子树置空，然后根节点循环为根节点的右子树
# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root == None:
            return
        
        while root.left or root.right:
            if root.left:
                pre = root.left
                while pre.right:
                    pre = pre.right

                pre.right = root.right
                root.right = root.left
                root.left = None
            
            root = root.right
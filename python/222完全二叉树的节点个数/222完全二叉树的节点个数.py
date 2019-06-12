"""
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6
"""

# 解答：计算左右子树高度，因为是完全二叉树，如果高度一致，则左子树一定是满二叉树，可以计算出左子树的个数，然后递归加上右子树个数即可
# 如果不一致，则右子树为比左子树低一层的满二叉树，同样计算右子树数目，然后递归加上左子树个数即可
# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        left_depth = self.depth(root.left)
        right_depth = self.depth(root.right)
        if left_depth == right_depth:
            return (1 << left_depth)  + self.countNodes(root.right)
        else:
            return (1 << right_depth) + self.countNodes(root.left)
        
    def depth(self, root):
        result = 0
        while root:
            root = root.left
            result += 1
        return result
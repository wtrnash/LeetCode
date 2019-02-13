"""
二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:

输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]

   3
  /
 1
  \
   2
示例 2:

输入: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

输出: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
进阶:

使用 O(n) 空间复杂度的解法很容易实现。
你能想出一个只使用常数空间的解决方案吗？
"""

# 解答：由于只有两个节点被交换了，所以可能中序遍历后，在升序数字串中存在一个降序对或者两个降序对，那这两种情况可以一起考虑
# 即将第一个降序对的前驱 和 （没有第二个降序对）第一个或者（有第二个降序对）第二个降序对的后继进行交换即可
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self.pre = None
        self.first = None
        self.second = None
        self.inOrder(root)
        self.first.val, self.second.val = self.second.val, self.first.val
    
    
    def inOrder(self, root):
        if not root:
            return
        
        self.inOrder(root.left)
        if self.pre:
            if not self.first and root.val <self.pre.val:
                self.first = self.pre
                
            if self.first and root.val < self.pre.val:
                self.second = root
        
        self.pre = root
        
        self.inOrder(root.right)
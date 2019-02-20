"""
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
"""

# 解答：类似105题的做法，只是把前序改成了后序，而后序最后一位是根节点，仍然用递归来做
# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        return self.recursion(inorder, 0, len(inorder) - 1, postorder, 0, len(postorder) - 1)
        
        
    def recursion(self, inorder, l1, r1, postorder, l2, r2):
        if l1 > r1:
            return None
        
        head = TreeNode(postorder[r2])
        
        i = l1
        for i in range(l1, r1 + 1):
            if inorder[i] == postorder[r2]:
                break
                
        
        head.left = self.recursion(inorder, l1, i - 1, postorder, l2, l2 + i - 1 - l1)
        head.right = self.recursion(inorder, i + 1, r1, postorder, l2 + i - l1, r2 - 1)
        
        return head
"""
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
"""

# 解答：前序遍历第一个为根节点，然后在中序遍历中找到该节点，左边为左子树的所有节点，右边为右子树的所有节点，然后根据数量对前序遍历也进行左右节点划分，然后递归调用即可
# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        return self.recursion(preorder, inorder)
    
    def recursion(self, preorder, inorder):
        if len(preorder) == 0:
            return None
        
        head_index = inorder.index(preorder[0])
        head = TreeNode(preorder[0])
        if head_index == 0:
            head.left = None
        else:
            head.left = self.recursion(preorder[1:head_index + 1], inorder[:head_index])
        
        if head_index == len(preorder) - 1:
            head.right = None
        else:
            head.right = self.recursion(preorder[head_index + 1:], inorder[head_index + 1:])
        
        return head
        
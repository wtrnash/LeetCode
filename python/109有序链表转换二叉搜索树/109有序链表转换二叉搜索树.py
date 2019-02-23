"""
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
"""

# 解答：利用快慢指针查找链表中间结点，然后递归进行二分

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    def sortedListToBST(self, head: 'ListNode') -> 'TreeNode':
        if not head:
            return None
        if not head.next:
            return TreeNode(head.val)
        
        last = head
        slow = head
        fast = head
        while fast.next and fast.next.next:
            last = slow
            slow = slow.next
            fast = fast.next.next
        
        root = TreeNode(slow.val)
        root.right = self.sortedListToBST(slow.next)
        
        if not head == slow:
            last.next = None
            root.left = self.sortedListToBST(head)
        
        
        return root
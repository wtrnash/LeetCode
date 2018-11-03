"""
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
说明:

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
"""
# 解答： 处理好返回的头结点，再处理好空的情况，进行链表两两交换即可
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        
        result = head.next
        temp = result.next
        result.next = head
        head.next = temp
        
        p = head
        q = p.next
        while q and q.next:
            p.next = q.next
            temp = q.next.next
            q.next.next = q
            q.next = temp
            p = q
            q = p.next
        
        return result
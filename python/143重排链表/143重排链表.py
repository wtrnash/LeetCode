"""
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
"""
# 解答：先利用快慢指针找到后面一半的起始点，然后将后面一半进行反转， 然后逐步插入前面的链表
# Definition for singly-linked list.
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if head == None or head.next == None:
            return
        
        fast = head
        slow = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        right = slow.next
        slow.next = None
        left = None
        now = right
        while now:
            right = now.next
            now.next = left
            left = now 
            now = right
        
        now = head
        while left:
            right = left.next
            left.next = now.next
            now.next = left
            now = left.next
            left = right
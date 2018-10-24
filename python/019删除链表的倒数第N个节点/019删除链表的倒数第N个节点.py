"""
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
"""

# 解答： 由于需要一趟扫描实现，所以可以定义两个“指针”，一个先往后n步，然后两个同时往后，等第一个到最后时，第二个正好是倒数第n个
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        q = p = head
        while n > 0:
            if p.next == None:          # 说明head是要删除的节点
                return head.next
            p = p.next
            n = n - 1
        while not p.next == None:
            p = p.next
            q = q.next
        
        q.next = q.next.next
        return head
            
"""
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
"""
# 解答：可以创建两个指针，分布将小于x的和大于、等于x的串起来，最后再首尾相连
# Definition for singly-linked list.
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        left = left_head = ListNode(-1)
        right = right_head = ListNode(-1)
        while head:
            if head.val < x:
                left.next = ListNode(head.val)
                left = left.next
            else:
                right.next = ListNode(head.val)
                right = right.next
            
            head = head.next
        
        left.next = right_head.next
        return left_head.next
                
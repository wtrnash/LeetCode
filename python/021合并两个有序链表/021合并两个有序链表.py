"""
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
"""

# 解答： 新建一个指针，然后在非空的情况下依次比较大小即可
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):         
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        p = result = ListNode(0)
        while not l1 is None and not l2 is None:
            if l1.val < l2.val:
                p.next = l1
                p = p.next
                l1 = l1.next
            else:
                p.next = l2
                p = p.next
                l2 = l2.next
        
        if not l1 is None:
            p.next = l1
        if not l2 is None:
            p.next = l2
        
        return result.next
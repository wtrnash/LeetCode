"""
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
"""

# 解答：分治法，递归地进行两个链表的合并

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
            self.val = x
            self.next = None

class Solution(object):       
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if not lists:
            return None
        
        return self.merge(lists, 0, len(lists) - 1)
        
    def merge(self, lists, start, end):
        if start == end:
            return lists[start]
        
        mid = start + int((end - start) / 2)
        left = self.merge(lists, start, mid)
        right = self.merge(lists, mid+1, end)
        return self.mergeTwoLists(left, right)
        
        
    def mergeTwoLists(self, first, second):
        p = head = ListNode(0)
        while first and second:
            if first.val < second.val:
                p.next = first
                p = p.next
                first = first.next
            else:
                p.next = second
                p = p.next
                second = second.next
        
        if first:
            p.next = first
        if second:
            p.next = second
        
        return head.next
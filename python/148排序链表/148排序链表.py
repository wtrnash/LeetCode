"""
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

"""

# 解答：先快慢指针找到中点，不断递归，然后将两个子串进行排序归并，再把整个归并
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        
        dummy = ListNode(0)
        dummy.next = head
        slow = dummy
        fast = dummy
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            
        fast = slow.next
        slow.next = None
        a = self.sortList(head)
        b = self.sortList(fast)
        return self.merge(a, b)
    
    def merge(self, a, b):
        dummy = ListNode(0)
        p = dummy
        while a and b:
            if a.val < b.val:
                p.next = a
                a = a.next
                p = p.next
            else:
                p.next = b
                b = b.next
                p = p.next
        
        if a:
            p.next = a
        
        if b:
            p.next = b
            
        return dummy.next
"""
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

"""
# 解答：快慢指针找到中点，然后翻转后半部分
# Definition for singly-linked list.
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
        fast = head
        slow = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        second = slow.next
        slow.next = False
        dummy = ListNode(-1)
        dummy.next = second
        prev = dummy.next
        cur = prev.next
        while cur:
            prev.next = cur.next
            cur.next = dummy.next
            dummy.next = cur
            cur = prev.next
        
        
        while head and dummy.next:
            if head.val != dummy.next.val:
                return False
            head = head.next
            dummy = dummy.next
        
        return True
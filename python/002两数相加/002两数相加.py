"""
题目：
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
"""

"""
解答：
两个单链表相加，如果为空，则该链表当前值为0，否则则为当前val，以carry作为进位来计算进位值。注意最后一个进位。
"""
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        p = head = ListNode(0)
        carry = 0
        while l1 != None or l2 != None:
            if l1 == None:
                x = 0
            else:
                x = l1.val
                l1 = l1.next
            if l2 == None:
                y = 0
            else:
                y = l2.val
                l2 = l2.next

            p.next = ListNode((x + y + carry) % 10)
            p = p.next
            
            if x + y + carry > 9:
                carry = 1
            else:
                carry = 0
        
        if carry == 1:
            p.next = ListNode(1)
        
        return head.next


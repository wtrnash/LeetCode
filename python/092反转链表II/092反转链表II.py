"""
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
"""

#解答：遍历到需要反转的前一个位置，每次将当前的插入到该位置后即可，直到反转完毕
class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None
         
class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        p = dummy
        i = 1
        while i < m:
            i += 1
            p = p.next
        
        pre = p
        cur = pre.next
        while i < n:
            t = cur.next
            cur.next = t.next
            t.next = pre.next
            pre.next = t
            i += 1
        
        return dummy.next
        
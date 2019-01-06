"""
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
"""

# 解答：先计算出链表的长度，向右移整个链表的长度等于没移动，所以直接k对其取余
# 从head开始，移动 n - k - 1次即为指向新头部的元素，然后进行连接即可

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head:
            return head
        
        n = 1
        p = head
        while p.next:   # 计算链表长度
            p = p.next
            n = n + 1
        
        k = k % n   # 取余
        
        p = head
        step =  n - k - 1      # 需移动n - k - 1步
        i = 0
        while i < step:
            i = i + 1
            p = p.next
        
            
        temp = p
        while p.next:
            p = p.next
        
        p.next = head       # 末尾指向头部
        head = temp.next    # 新的头部
        temp.next = None    # 新头部前一个元素指向None
        
        return head
        
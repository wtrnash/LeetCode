"""
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3
"""

# 解答：在head前加一个节点来处理即可
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = dummy = ListNode(-1)
        dummy.next = pre.next = head    # head前加一个节点，方便处理头结点
        while pre.next:
            cur = pre.next
            while cur.next and cur.val == cur.next.val: # 把相等的都跳过
                cur = cur.next
            if pre.next == cur: # 说明不相等，则往后移
                pre = pre.next
            else:
                pre.next = cur.next # 跳过当前之前没跳过的第一个重复的元素
        
        return dummy.next
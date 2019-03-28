"""
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。


示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。


示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

"""
# 解答：用快慢指针做。 假设环第一个节点距起点为a， 快慢指针相遇的点距起点为a + b。沿相遇点到环的距离为c。 那么由于 快指针走了 a + b + c + b，是慢指针a + b的两倍
# 所以 c = a。所以从相遇点开始，满指针走c的距离会和同时另一指针从起点走a的距离相遇，因为a=c，返回相遇时的节点即可 
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None
        fast = head
        slow = head
        while fast.next and fast.next.next:
            fast = fast.next.next
            slow = slow.next
            if fast == slow:
                p = head
                while True:
                    if p == slow:
                        return p
                    slow = slow.next
                    p = p.next
         
                
        return None
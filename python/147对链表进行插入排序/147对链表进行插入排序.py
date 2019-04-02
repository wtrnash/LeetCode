"""
对链表进行插入排序。


插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5
"""
# 解答：加一个头指针，记录首元素的位置，先把当前元素和下一个元素比较，下一个大的话则继续遍历，小的话，则从头开始比较，比下一个元素小则插入。
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if head == None:
            return head
        dummy = ListNode(-1)
        dummy.next = head
        p = head
        while p.next:
            if p.next.val >= p.val:
                p = p.next
            else:
                temp = dummy
                while temp.next.val < p.next.val:
                    temp = temp.next
                    
                q = p.next
                p.next = q.next
                q.next = temp.next
                temp.next = q
        
        return dummy.next
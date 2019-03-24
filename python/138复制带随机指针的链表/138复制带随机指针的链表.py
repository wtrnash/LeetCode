"""
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深拷贝。 



输入：
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

解释：
节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
 

提示：

你必须返回给定头的拷贝作为对克隆列表的引用。

"""

# 解答：先将该节点的复制连为next，该节点原来的next连成其复制的next，相当于构造了新节点和原节点的映射
# 然后新节点的random就等于原节点的random的next
# 然后将两串链表分开即可

# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random

class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if head == None:
            return None
        
        p = head
        while p:
            temp = Node(p.val, p.next, None)
            p.next = temp
            p = p.next.next
        
        p = head
        while p:
            if p.random:
                p.next.random = p.random.next
            
            p = p.next.next
        
        p = head
        new_head = q = p.next
        while p:
            p.next = q.next
            if q.next:
                q.next = q.next.next
            p = p.next
            q = q.next
        
        return new_head
            

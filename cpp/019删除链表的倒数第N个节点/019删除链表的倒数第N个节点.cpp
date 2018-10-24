/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

//解答 先遍历一遍求出节点数，然后用倒数的和节点数计算出正数第几个，并做删除操作

# include<iostream>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* p = head, *q;
        while(p != NULL)
        {
            p = p->next;
            count++;
        }
        
        p = head;
        for(int i = 0; i < count - n; i++)
        {
            q = p;
            p = p->next;
        }
        if(p == head)   //删除要删除节点为头结点的情况
        {
            head = head->next;
            delete p;
        }
        else    
        {
            q->next = p->next;
            delete p;
        }

        return head;
    }
};
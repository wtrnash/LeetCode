/*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
说明:

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/
//解答： 处理好返回的头结点，再处理好空的情况，进行链表两两交换即可
#include <iostream>
using namespace std;
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return head;
        
        ListNode* result = head->next;
        ListNode* temp = result->next;
        result->next = head;
        head->next = temp;
        
        ListNode* p = head;
        ListNode *q = p->next;
        while(p->next != NULL)
        {
            if(q->next == NULL)
                break;
            
            p->next = q->next;
            temp = q->next->next;
            q->next->next = q;
            q->next = temp;
            p = q;
            q = p->next;
        }
        
        return result;
        
    }
};
/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
*/
//解答：先利用快慢指针找到后面一半的起始点，然后将后面一半进行反转， 然后逐步插入前面的链表
#include <iostream>

/**
 * Definition for singly-linked list.
 */ struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head) {
      if(!head || !head->next)
          return;
        
        ListNode* fast, *slow;
        fast = slow = head;
        while(fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *right = slow->next;
        slow->next = NULL;
        ListNode* left = NULL;
        ListNode* now = right;
        while(now)
        {
            right = now->next;
            now->next = left;
            left = now;
            now = right;
        }
        
        now = head;
        while(left)
        {
            right = left->next;
            left->next = now->next;
            now->next = left;
            now = left->next;
            left = right;
        }
        
        
        
    }
};
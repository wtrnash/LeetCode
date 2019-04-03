/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5

*/

//解答：先快慢指针找到中点，不断递归，然后将两个子串进行排序归并，再把整个归并
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        ListNode* a = sortList(head);
        ListNode* b = sortList(fast);
        return merge(a, b);
    }
    
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while(a && b)
        {
            if(a->val < b->val)
            {
                p->next = a;
                a = a->next;
                p = p->next;
            }
            else
            {
                p->next = b;
                b = b->next;
                p = p->next;
            }
        }
        
        while(a)
        {
            p->next = a;
            break;
        }
        
        while(b)
        {
            p->next = b;
            break;
        }
        
        return dummy->next;
        
    }
};
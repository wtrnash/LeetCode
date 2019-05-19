/*
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/
//解答：加一个头指针后遍历链表即可
#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 */ struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        while(p->next)
        {
            if(p->next->val == val)
            {
                ListNode* q = p->next;
                p->next = q->next;
                delete q;
            }
            else
                p = p->next;
        }
        
        return dummy->next;
    }
};
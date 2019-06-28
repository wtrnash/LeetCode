/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

*/
//解答：快慢指针找到中点，然后翻转后半部分
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* dummy = new ListNode(-1);
        dummy->next = second;
        ListNode* prev = dummy->next;
        ListNode* cur = prev->next;
        while(cur)
        {
            prev->next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = prev->next;
        }
        
        while(head && dummy->next)
        {
            if(head->val != dummy->next->val)
                return false;
            head = head->next;
            dummy = dummy->next;
        }
        
        return true;
        
        
    }
};
/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

*/

//解答：链表操作，比082简单很多，因为不用把重复的都删除，而第一个元素可以留着。所以就遇到下一个元素和当前相等，就把下一个删了。如果不相等，则链表指向下一个即可。
/**
 * Definition for singly-linked list.
 */

#include <iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode* p = head;
        while(p->next)
        {
            if(p->val == p->next->val)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }
        
        return head;
    }
};
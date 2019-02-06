/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL
*/

//解答：遍历到需要反转的前一个位置，每次将当前的插入到该位置后即可，直到反转完毕
#include <iostream>
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        int i = 1;
        ListNode *cur = dummy;
        ListNode *t;
        while(i < m)
        {
            cur = cur->next;
            i++;
        }
           
        
        ListNode *pre = cur;    //记录前驱节点，以及当前节点。在反转过程中，每次反转完一个节点后，当前节点总是反转的这几个节点中的最后一个节点
        cur = pre->next;
        
        while(i < n)
        {
            t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;  //新的节点插到前驱节点之后
            i++;
        }
        
        return dummy->next;
    }
};

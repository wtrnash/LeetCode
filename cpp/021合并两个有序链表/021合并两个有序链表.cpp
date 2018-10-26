/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

// 解答： 新建一个指针，然后在非空的情况下依次比较大小即可
//Definition for singly-linked list.
# include <iostream>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *p = result;
        //两个都非空时
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }
        
        //只有一个非空时
        while(l1 != NULL)
        {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }
        
        while(l2 != NULL)
        {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
        
        return result->next;
        
    }
};
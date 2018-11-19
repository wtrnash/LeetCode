/*
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/
//解答：先确定有结点总数，每k个分别进行链表反转即可。
#include <iostream>
using namespace std;
// 链表结构体
struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1)
            return head;
        
        //确定结点总数
        int count = 0;
        ListNode *p = head;
        while(p != NULL)
        {
            count++;
            p = p->next;
        }
        
        
        ListNode* r = new ListNode(-1);
        r->next = head;
        ListNode* pre = r;
        ListNode* cur;
        while(count >= k)
        {
            cur = pre->next;
            //按每段进行翻转
            for(int i = 1; i < k; i++)
            {
                ListNode *temp = cur->next;
                cur->next = temp->next; 
                temp->next = pre->next;
                pre->next = temp;
                
            }
            pre = cur;
            count -= k;
        }
        
        return r->next;
        
    }
    
  
};
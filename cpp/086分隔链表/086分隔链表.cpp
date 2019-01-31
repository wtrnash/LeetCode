/*
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5
*/

//解答：任务主要是找到第一个大于或等于x的节点。在没有找到该节点前，遇到小于的都直接跳到下一个。
//直到找到大于或等于x的第一个节点，记录其前驱的节点。 之后，如果找到大于或等于x的节点，都直接跳到下一个。
//一旦碰到小于x的节点，则将其移到大于或等于x的第一个节点之前。
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(-1); //创造一个头结点，这样对原本的头结点不用特殊处理
        dummy->next = head;
        ListNode *p = dummy;    
        ListNode *firstBigger = NULL;
        ListNode *temp;
        while(p->next)
        {
            if(p->next->val >= x)   //如果大于或等于x
            {
                if(!firstBigger)    //记录第一个大于或等于x的前驱节点
                    firstBigger = p;
                
                p = p->next;
            }
            else    //如果小于x
            {
                if(firstBigger != NULL) //已经找到第一个大于或等于x的节点
                {
                    temp = p->next;
                    p->next = temp->next;
                    temp->next = firstBigger->next;
                    firstBigger->next = temp;
                    firstBigger = temp; 
                }
                else    //没找到则往后移
                     p = p->next;
                
            }
         
               
        }
        
        return dummy->next;
        
        
    }
};
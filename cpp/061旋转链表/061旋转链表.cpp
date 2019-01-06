/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
*/

//解答：先计算出链表的长度，向右移整个链表的长度等于没移动，所以直接k对其取余
//然后循环k次，每次找到倒数第二个节点和最后一个节点，最后一个节点指向第一个节点，head指向最后一个节点，倒数第二个节点指向NULL
//即完成一步的向右移。剩下循环即可
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
    ListNode* rotateRight(ListNode* head, int k) {
       if(head == NULL)
           return head;
        ListNode *p = head;
        int nums = 1;
        while(p->next != NULL)  //计算链表长度
        {
            p = p->next;
            nums++;
        }
        
        k %= nums;  //取余
        while(k > 0)    //循环K次
        {
            p = head;
            while(p->next->next != NULL)    //找到倒数第二个节点。 由于如果链表只有一个节点的话k取余一定为0，所以进循环的链表一定至少两个节点,p->next一定不为NULL
            {
                p = p->next;
            }
            
            p->next->next = head;   //最后一个节点指向第一个节点
            head = p->next; //head指向最后一个节点
            p->next = NULL; //倒数第二个节点指向NULL
            k--;
        }
        
        
        return head;
    
    }
};
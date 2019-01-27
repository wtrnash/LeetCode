/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3
*/

//解答：链表操作。注意删除下一个元素和当前元素，以及是否头结点的区别
 #include <vector>
 #include <iostream>
 using namespace std;
 
/**
 * Definition for singly-linked list.
 * 
 */
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
        ListNode *p = head;
        ListNode *q;
        bool needDelete = false;    //记录下一个需不需要删除
        while(p->next != NULL)
        {
            if(p->next->val == p->val)  //相等时删除当前结点
            {
                if(p == head)   //判断是否是头结点
                {
                    head = p->next;
                    delete p;
                    p = head;
                }
                else
                {
                    q->next = p->next;
                    delete p;
                    p = q->next;
                }
                
                needDelete = true;
            }
            else if(!needDelete)    //不相等时判断当前元素是否和上一个元素相等
            {
                q = p;
                p = p->next;
            }
            else
            {
                if(p == head)
                {
                    head = p->next;
                    delete p;
                    p = head;
                }
                else
                {
                    q->next = p->next;
                    delete p;
                    p = q->next;
                }
                
              
                needDelete = false;
            }
        }
        
        if(needDelete)  //判断最后一个p是否和上一个元素相同
        {
            if(p == head)
                {
                    head = p->next;
                    delete p;
                    p = head;
                }
                else
                {
                    q->next = p->next;
                    delete p;
                    p = q->next;
                }
        }
        
        return head;
    }
};
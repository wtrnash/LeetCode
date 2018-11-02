/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*/

//解答， 每次取k个链表里最小的连入链表，一直到全部为空为止。
#include <vector>
#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        bool empty = true;  //判断是否所有都为空
        bool isFirst = true;    //判断是否是每次循环的第一次
        ListNode* p = head;
        int minIndex;
        do{
            empty = true;
            isFirst = true;
            for(int i = 0; i < lists.size(); i++)
            {
                if(lists[i] != NULL && isFirst)
                {
                    isFirst = false;
                    empty = false;
                    minIndex = i;   //是每次循环的第一次则直接先取该次
                }
                else if(lists[i] != NULL && !isFirst)
                {
                    empty = false;
                    if(lists[i]->val < lists[minIndex]->val)    //和之前的minIndex比较大小
                        minIndex = i;
                }
            }
            
            if(!empty)  //如果非空
            {
                p->next = lists[minIndex];
                p = p->next;
                lists[minIndex] = lists[minIndex]->next;
            }
       
        }while(!empty);
        
      return head->next;
    }
};
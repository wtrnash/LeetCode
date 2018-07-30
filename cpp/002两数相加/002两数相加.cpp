/*
题目：
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/*
解答：
实际上是对两个单链表进行操作，考虑两个单链表当前都非空以及其中一个空的情况，由于每个节点存储的都是一位，所以要考虑
进位的情况。不要忘了当两个链表都为空时最后一个进位也要考虑。
*/

  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);   //头指针，不存储具体数字
        ListNode *p = head;
        int carry = 0;  //进位
        //如果两个都非空
        while(l1 != nullptr && l2 != nullptr)
        {
            p->next = new ListNode(0);
            p = p->next;
            //处理进位
            if(l1->val + l2->val + carry > 9)
            {
                p->val = l1->val + l2->val + carry - 10;
                carry = 1;
            }
            else
            {
                p->val = l1->val + l2->val + carry;
                carry = 0;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        //只有l1非空
        while(l1 != nullptr)
        {
            p->next = new ListNode(0);
            p = p->next;
            if(l1->val + carry > 9)
            {
                p->val = l1->val + carry - 10;
                carry = 1;
            }
            else
            {
                p->val = l1->val + carry;
                carry = 0;
            }
          
            l1 = l1->next;
        }

        //只有l2非空
        while(l2 != nullptr)
        {
            p->next = new ListNode(0);
            p = p->next;
            if(l2->val + carry > 9)
            {
                p->val = l2->val + carry - 10;
                carry = 1;
            }
            else
            {
                p->val = l2->val + carry;
                carry = 0;
            }
          
            l2 = l2->next;
        }
        //处理最后的进位
        if(carry == 1)
        {
            p->next = new ListNode(1);
        }

        return head->next;

    }
};
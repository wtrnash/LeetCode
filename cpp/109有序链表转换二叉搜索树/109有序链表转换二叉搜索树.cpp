/*

给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/

//解答：类似108用递归，只是将数组的二分改成了链表的二分
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */ struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
/**
 * Definition for a binary tree node.
 */ struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int count = 0;
        ListNode* p = head;
        while(p)
        {
            count++;
            p = p->next;
        }
        return recursion(head, count);
        
    }
    
    TreeNode* recursion(ListNode* head, int count)
    {
        if(count <= 0)
            return NULL;
        
        int mid = (1 + count) / 2;
        ListNode* p = head;
        for(int i = 1; i < mid; i++)
        {
            p = p->next;
        }
        
        TreeNode* root = new TreeNode(p->val);
        root->left = recursion(head, mid - 1);
        root->right = recursion(p->next, count - mid);
        return root;
        
    }
};
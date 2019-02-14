/*
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例 2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:

输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false
*/

//解答：利用递归，分别判断是否同时为NULL,结点值相不相同以及左右子树相不相同
#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return recursion(p, q);
    }
    
    bool recursion(TreeNode* p, TreeNode* q)
    {
        if(p == NULL)
        {
            if(q == NULL)
                return true;
            else
                return false;
        }
        
        if(q == NULL)
        {
            if(p == NULL)
                return true;
            else
                return false;
        }
        
        if(q->val == p->val)
        {
            return recursion(p->left, q->left) && recursion(p->right, q->right);
        }
        else
            return false;
    }
};
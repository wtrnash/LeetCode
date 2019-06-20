/*
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/
//解答：递归翻转左右子树即可
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        
        
        return root;
    }
};
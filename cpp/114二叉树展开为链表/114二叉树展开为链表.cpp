/*
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

*/

//解答：递归进行后序遍历，然后将左子树移到右子树，将右子树移到左子树的最右子树之后
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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* temp = root->right;
        
        root->right = root->left;
        root->left = NULL;
        while(root->right)
        {
            root = root->right;
        }
        
        root->right = temp;
    }
};
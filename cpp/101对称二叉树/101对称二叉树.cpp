/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
*/

//解答：用递归做。将树的根节点作为两个参数分别传递。先看是不是都为空。都不为空则看值是不是相等。然后树1的左子树和树2的右子树比，树1的右子树和树2的左子树比。
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
    bool isSymmetric(TreeNode* root) {
       return recursion(root, root);
    }
    
    bool recursion(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2)
            return true;
        
        if(!root1 || !root2)
            return false;
        
        if(root1->val != root2->val)
            return false;
        
        return recursion(root1->left, root2->right) && recursion(root1->right, root2->left);
        
        
    }
};
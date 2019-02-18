/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

*/

//解答：递归实现，如果当前为空就返回0，当前有就返回 1 + 左右子树中最深的深度
#include<cmath>
#include<iostream>
using namespace std;
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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        else
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

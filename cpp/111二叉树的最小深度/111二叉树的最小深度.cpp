/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.
*/

//解答：递归求深度。按当前为空、子树为空、其中一个子树为空以及普通情况来判断
#include <iostream>
#include <algorithm>
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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
       
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(left == 0 && right == 0)
            return 1;
        
        if(left == 0)
            return 1 + right;
        
        if(right == 0)
            return 1 + left;
        
        return 1 + min(left, right);
        
    }
};
/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

//解答：类似题112进行递归，只是其中加上每个节点的元素
#include <iostream>
#include <vector>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> temp;
        recursion(root, result, temp, sum);
        return result;
    }
    
    void recursion(TreeNode* root, vector<vector<int>>& result, vector<int> temp, int sum)
    {
        if(!root)
            return;
        
        temp.push_back(root->val);
        if(!root->left && !root->right && sum == root->val)
        {
            result.push_back(temp);
            return;
        }
        
        recursion(root->left, result, temp, sum - root->val);
        recursion(root->right, result, temp, sum - root->val);
    }
};
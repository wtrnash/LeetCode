/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]
*/
//解答：类似102，将最后的结果逆序即可
#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* t;
        int count;
        while(!q.empty())
        {
            count = q.size();
            temp.clear();
            while(count > 0)
            {
                t = q.front();
                q.pop();
                if(t->left)
                {
                    q.push(t->left);
                }
                
                if(t->right)
                {
                    q.push(t->right);
                }
                
                temp.push_back(t->val);
                count--;
            }
            
            result.push_back(temp);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
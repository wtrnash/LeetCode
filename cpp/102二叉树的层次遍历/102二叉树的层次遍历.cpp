/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
*/

//解答：利用队列实现层序遍历，并用count进行计数
#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        
        return result;
    }
};
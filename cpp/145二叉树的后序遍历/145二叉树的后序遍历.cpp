/*
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/
#include <iostream>
#include <vector>
using namespace std;
//解答：递归做
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
    
    void dfs(TreeNode* root, vector<int>& result){
        if(!root)
            return;
        
        dfs(root->left, result);
        dfs(root->right, result);
        result.push_back(root->val);
    }
};
/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

//解答：用递归实现的话很简单，中序遍历就是先遍历左子树到底，然后访问当前值，再访问右子树
#include <vector>
#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        recursion(result, root);
        
        return result;

    }
    
    void recursion(vector<int> &result, TreeNode* root)
    {
        if(!root)
            return;
        
        recursion(result, root->left);
        result.push_back(root->val);
        recursion(result, root->right);
    }
};
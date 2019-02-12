/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
*/

//解答：递归做，然后要保证子树的值在限定范围内，所以需要把上下限也作为参数传进去
#include <iostream>
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
    bool isValidBST(TreeNode* root) {
        long long minVal = -2147483649;
        long long maxVal = 2147483648;
        return recursion(root, minVal, maxVal);
    }
    
    bool recursion(TreeNode* root, long long minVal, long long maxVal)
    {
         if(!root)
            return true;
        
        if(root->val <= minVal || root->val >= maxVal)
            return false;
        
        bool result = true;
        
        if(root->left)
        {
            if(root->val <= root->left->val)
                return false;
            
            result = recursion(root->left, minVal, root->val);    
        }
        
        if(root->right)
        {
            if(root->val >= root->right->val)
                return false;
            
            result = result && recursion(root->right, root->val, maxVal);
        }
        
        return result;
    }
};
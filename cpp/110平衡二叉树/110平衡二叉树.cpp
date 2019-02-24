/*

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。
*/

//解答：用递归做，返回值为左右子树是否平衡，并用引用的方式传回当前的高度
#include <iostream>
#include <algorithm>
#include <cmath>
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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalanced(root, height);
    }
    
    bool isBalanced(TreeNode* root, int& height)
    {
       if(!root)
       {
           height = 0;
           return true;
       }
        
       int left;
       int right;
       if(isBalanced(root->left, left) && isBalanced(root->right, right))
       {
           if(abs(left - right)<=1)
           {
               height = max(left, right) + 1;
               return true;
           }
           else
               return false;
       }
        else
            return false;
    }
};
/*
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
*/
//解答：中序遍历然后返回第k个值
#include <vector>
#include <iostream>
#include <stack>
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s; 
        vector<int> result;
        while(!s.empty() || root)
        {
            while(root)
            {
                s.push(root);
                root = root->left;
            }
            
            TreeNode* temp = s.top();
            s.pop();
            result.push_back(temp->val);
            root = temp->right;
        }
        return result[k - 1];
    }
};
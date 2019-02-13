/*
二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:

输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]

   3
  /
 1
  \
   2
示例 2:

输入: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

输出: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
进阶:

使用 O(n) 空间复杂度的解法很容易实现。
你能想出一个只使用常数空间的解决方案吗？
*/

//解答：先中序遍历获取所有数字，然后进行升序排序，再中序遍历依次赋给所有节点
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 */struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> result;
        getInOrder(root, result);
        sort(result.begin(), result.end());
        int index = 0;
        setInOrder(root, result, index);
    }
    
    void getInOrder(TreeNode* root, vector<int>& result)
    {
        if(!root)
            return;
        
        getInOrder(root->left, result);
        result.push_back(root->val);
        getInOrder(root->right, result);
    }
    
    void setInOrder(TreeNode* root, vector<int>& result, int& index)
    {
        if(!root)
            return;
        
        setInOrder(root->left, result, index);
        root->val = result[index++];
        setInOrder(root->right, result, index);
    }
};
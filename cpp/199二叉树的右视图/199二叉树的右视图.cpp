/*

给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*/
//解答:层序遍历，每层最后一个放入结果中
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        int count;
        TreeNode* temp;
        while(!q.empty())
        {
            count = q.size();
            while(count > 0)
            {
                temp = q.front();
                q.pop();
                count--;

                 if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            if(temp)
                result.push_back(temp->val);
        }
        
        return result;
        
    }
};
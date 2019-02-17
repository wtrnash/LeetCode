/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

*/

//解答：类似102的层序遍历，只不过多用一个变量i来记录当前是奇数还是偶数，偶数就和102一样处理，奇数就先存入栈，再从栈加入vector，达到逆序的效果
#include <iostream>
#include <vector>
#include <stack>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector <int>> result;
        if(!root)
        {
            return result;
        }
        
        vector<int> temp;
        queue<TreeNode *> q;
        int i = 0;
        stack<int> s;
        int count;
        q.push(root);
        TreeNode *t;
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
                if(i % 2 == 0)
                    temp.push_back(t->val);
                else
                {
                    s.push(t->val);
                }
                
                
                count -= 1;
            }
            
            if(i % 2)
            {
                while(!s.empty())
                {
                    temp.push_back(s.top());
                    s.pop();
                }
            }
            
            result.push_back(temp);
            i++;
        }
        return result;
    }
};
/*
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
//解答：利用递归，分别求得左右子树可能的情况，然后分别组合
#include <iostream>
#include <vector>
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n != 0)
            result = recursion(1, n);
        return result;
    }
    
    vector<TreeNode*> recursion(int low, int high)
    {
        vector<TreeNode*> result;
        if(low > high)
        {
            result.push_back(NULL);
            return result;
        }
        
        for(int i = low; i <= high; i++)
        {
            vector<TreeNode*> left = recursion(low, i - 1);
            vector<TreeNode*> right = recursion(i + 1, high);
            
            for(int j = 0; j < left.size(); j++)
            {
                for(int k = 0; k < right.size(); k++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }
    
    
};
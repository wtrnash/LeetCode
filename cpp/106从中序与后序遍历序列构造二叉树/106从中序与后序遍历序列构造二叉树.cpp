/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/

//解答：类似105题的做法，只是把前序改成了后序，而后序最后一位是根节点，仍然用递归来做
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, int l1, int r1, vector<int>& postorder, int l2, int r2)
    {
        if(l1 > r1)
            return NULL;
        
        TreeNode* head = new TreeNode(postorder[r2]);
        int i;
        for(i = l1; i <= r1; i++)
        {
            if(inorder[i] == postorder[r2])
                break;
        }
        
        head->left = buildTree(inorder, l1, i - 1, postorder, l2, l2 + i - l1 - 1);
        head->right = buildTree(inorder, i + 1, r1, postorder, l2 + i - l1, r2 - 1);
            
        return head;
        
        
    }
};

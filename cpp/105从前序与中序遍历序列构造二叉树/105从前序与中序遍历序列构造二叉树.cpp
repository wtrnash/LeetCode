/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/

//解答：前序遍历第一个为根节点，然后在中序遍历中找到该节点，左边为左子树的所有节点，右边为右子树的所有节点，然后根据数量对前序遍历也进行左右节点划分，然后递归调用即可
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
        return recursion(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
        
    }
    
    TreeNode* recursion(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2)
    {
        if(l1 > r1)
            return NULL;
        if(l1 == r1)
        {
            return new TreeNode(preorder[l1]);
        }
        
        int i;
        for(i = l2; i <= r2; i++)
        {
            if(inorder[i] == preorder[l1])
                break;
        }
        
        TreeNode* head = new TreeNode(preorder[l1]);
        head->left = recursion(preorder, l1 + 1, l1 + i - l2, inorder, l2, i - 1);
        head->right = recursion(preorder, l1 + i - l2 + 1, r1, inorder,  i + 1, r2);
        
        return head;
    }
};
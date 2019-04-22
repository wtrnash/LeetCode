/*
实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

调用 next() 将返回二叉搜索树中的下一个最小的数。

示例：

BSTIterator iterator = new BSTIterator(root);
iterator.next();    // 返回 3
iterator.next();    // 返回 7
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 9
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 15
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 20
iterator.hasNext(); // 返回 false
 

提示：

next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。
你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 中至少存在一个下一个最小的数。
*/
//解答：中序遍历获得升序数字串，记录当前访问到第几个即可
#include <iostream>
#include <vector>
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
 
class BSTIterator {
public:
    int current;
    vector<int> tree;
    BSTIterator(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode*> s;
        while(!s.empty() || root)
        {
           while(root)
           {
               s.push(root);
               root = root->left;
           }
            
           if(!s.empty())
           {
               TreeNode* temp = s.top();
               s.pop();
               tree.push_back(temp->val);
               root = temp->right;
           }
        }
        
        current = 0;
    }
    
    /** @return the next smallest number */
    int next() {
        return tree[current++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(current >= tree.size())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
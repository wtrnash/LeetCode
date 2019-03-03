/*
给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

示例：



输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":null,"next":null,"right":{"$id":"6","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":null,"right":null,"val":7},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"6","left":null,"next":null,"right":{"$ref":"5"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"6"},"val":1}

解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 

提示：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

*/

//解答：类似116，但要考虑左右子树为空的情况，分别做处理。这里用递归做。然后要注意先递归右边，连上右边的next，这样再左边时子树可以相连
#include <iostream>
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        
        if(!root->left && !root->right)
        {
            return root;
        }
        
        Node* p;
        if(root->left && root->right)
        {
            root->left->next = root->right;
            p = root->right;
        }
        
        if(root->left && !root->right)
        {
            p = root->left;
         
        }
        
        if(!root->left && root->right)
        {
            p = root->right;
        }
        
        
        Node *q = root->next;
        while(q)
        {
            if(q->left)
            {
                p->next = q->left;
                break;
            }
            else if(q->right)
            {
                p->next = q->right;
                break;
            }
            else
            {
                q = q->next;
            }
        }
        
        connect(root->right);
        connect(root->left);
        
        return root;        
    }
};
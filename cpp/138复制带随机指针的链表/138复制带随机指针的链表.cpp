/*
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深拷贝。 



输入：
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

解释：
节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
 

提示：

你必须返回给定头的拷贝作为对克隆列表的引用。

*/

//解答：利用hashmap存储旧节点和新节点的对应关系，从而完成随机指针的映射
#include <iostream>
#include <map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        
        map<Node*, Node*> m;
        Node* dummy = new Node(0, NULL, NULL);
        Node * cur = head;
        Node* s = dummy;
        while(cur != NULL)
        {
            s->next = new Node(cur->val, NULL, NULL);
            m[cur] = s->next;   //建立新老指针的对应关系
            s = s->next;
            cur = cur->next;
        }
        
        //处理随机节点
        cur = head;
        while(cur != NULL)
        {
            m[cur]->random = m[cur->random]; 
            cur = cur->next;
        }
        return dummy->next;
    }
};
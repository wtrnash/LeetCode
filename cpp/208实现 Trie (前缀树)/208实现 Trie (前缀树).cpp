/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。

*/

//解答：26叉树，再用一个标记记录当前字符串的数量
#include <iostream>
#include <string>
using namespace std;
class Node{
public:        
    int num;
    Node* next[26];
    Node(){
        num = 0;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};
    
class Trie {
public:

    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(p->next[word[i] - 'a'] == NULL)
            {
                p->next[word[i] - 'a'] = new Node();
            }
            
            p = p->next[word[i] - 'a'];
        }
        
        p->num += 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(p->next[word[i] - 'a'] == NULL)
                return false;
            
            p = p->next[word[i] - 'a'];
        }
        
        if(p->num == 0)
            return false;
        
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         Node* p = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(p->next[prefix[i] - 'a'] == NULL)
                return false;
            
            p = p->next[prefix[i] - 'a'];
        }
              
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
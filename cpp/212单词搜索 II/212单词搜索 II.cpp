/*
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

输入: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]
说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:

你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。

*/
//解答：直接用dfs，超时
/*
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

    Trie() {
        root = new Node();
    }
    
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

class Solution {
public:
    Trie trie;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> t;
        
        if(board.size() == 0 || board[0].size() == 0 || words.size() == 0)
            return vector<string>();
        
        //for(int i = 0; i < words.size(); i++)
        //    trie.insert(words[i]);
        vector<vector <bool>> isUsed(board.size(), vector<bool> (board[0].size(), false));
        
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < board.size(); j++)
            {
                for(int k = 0; k < board[0].size(); k++)
                {
                    if(dfs(board, j, k, words[i], isUsed))
                       t.insert(words[i]);
                }
            }
        }
        vector<string> result(t.begin(), t.end());
        return result;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, string word, vector<vector<bool>> isUsed)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if(isUsed[i][j])
            return false;
        if(word[0] != board[i][j])
            return false;
        
        isUsed[i][j] = true;
        string temp = word.substr(1);
        if(temp.size() == 0)
            return true;
        
        if(dfs(board, i + 1, j, temp, isUsed))
            return true;
         if(dfs(board, i - 1, j, temp, isUsed))
            return true;
         if(dfs(board, i, j + 1, temp, isUsed))
            return true;
         if(dfs(board, i, j - 1, temp, isUsed))
            return true;
        
        return false;
    }
};
*/
//然后使用前缀树来记录要搜索的单词做约束，这样就从o(n^3)变成了o(n^2)的复杂度，然后再dfs
#include <iostream>
#include <set>
#include <string>
#include <vector>
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

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> t;
        
        if(board.size() == 0 || board[0].size() == 0 || words.size() == 0)
            return vector<string>();
        
        Trie trie;
        for(int i = 0; i < words.size(); i++)
            trie.insert(words[i]);
        
        vector<vector <bool>> isUsed(board.size(), vector<bool> (board[0].size(), false));
        
        Node* root = trie.root;
        string word;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(root->next[board[i][j] - 'a'] != NULL)
                    dfs(board, isUsed, i, j, root->next[board[i][j] - 'a'], t, word);
            }
        }
        vector<string> result(t.begin(), t.end());
        return result;
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>> isUsed, int i, int j, Node* node, set<string>& t, string word)
    {
        word += board[i][j];
        isUsed[i][j] = true;
        if(node->num != 0)
            t.insert(word);
        if(i > 0 && !isUsed[i - 1][j] && node->next[board[i - 1][j] - 'a'] != NULL){
              dfs(board, isUsed, i - 1, j, node->next[board[i - 1][j] - 'a'], t, word);
        }
         if(i < board.size() - 1 && !isUsed[i + 1][j] && node->next[board[i + 1][j] - 'a'] != NULL){
              dfs(board, isUsed, i + 1, j, node->next[board[i + 1][j] - 'a'], t, word);
        }
         if(j > 0 && !isUsed[i][j - 1] && node->next[board[i][j - 1] - 'a'] != NULL){
              dfs(board, isUsed, i, j - 1, node->next[board[i][j - 1] - 'a'], t, word);
        }
         if(j < board[0].size() - 1 && !isUsed[i][j +  1] && node->next[board[i][j + 1] - 'a'] != NULL){
              dfs(board, isUsed, i, j + 1, node->next[board[i][j + 1] - 'a'], t, word);
        }
    }
};
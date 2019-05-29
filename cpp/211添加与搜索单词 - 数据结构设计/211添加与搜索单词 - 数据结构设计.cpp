/*
设计一个支持以下两种操作的数据结构：

void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
说明:

你可以假设所有单词都是由小写字母 a-z 组成的。

*/

//解答：使用字典树来做。遇到'.'时递归进行求解
#include <iostream>
#include <string>
using namespace std;
class Node{
public:
    Node* next[26];
    int num;
    Node(){
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
        num = 0;
    }
};
class WordDictionary {
public:
    Node* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* p = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(p->next[word[i] - 'a'] == NULL)
                p->next[word[i] - 'a'] = new Node();
            p = p->next[word[i] - 'a'];
        }
        p->num += 1;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
       return dfs(word, root);
    }
    
    bool dfs(string word, Node* p)
    { 
        if(word.size() == 0)
        {
            if(p->num == 0)
                return false;
            else
                return true;
        }
        
        if(word[0] != '.')
        {
            if(!p->next[word[0] - 'a'])
                return false;
            
            return dfs(word.substr(1), p->next[word[0] - 'a']);
        }
        else
        {
            for(int i = 0; i < 26; i++)
            {
                if(p->next[i]){
                    if(dfs(word.substr(1), p->next[i]))
                        return true;
                }
            }
            
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
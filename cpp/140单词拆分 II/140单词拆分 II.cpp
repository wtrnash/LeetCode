/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]
示例 2：

输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。
示例 3：

输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]
*/

//解答：先用dfs尝试还是超时
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
/*
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        string temp;
        dfs(result, temp, s, wordDict);
        return result;
    }
    
    void dfs(vector<string>& result, string temp, string s, vector<string>& wordDict)
    {
        if(s.length() == 0)
        {
            result.push_back(temp);
            return;
        }
        
        for(int i = 0; i < wordDict.size(); i++)
        {
            int n = wordDict[i].length();
            string t = s.substr(0, n);
            if(wordDict[i] == t)
            {
                int l = temp.size();
                if(l != 0)
                {
                    temp += " ";
                }
                temp += wordDict[i];
                dfs(result, temp, s.substr(n), wordDict);
                temp = temp.substr(0, l);
            }
        }
        
        return;
    }
};
*/

//先使用dp判断s是否可分，再进行dfs
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        string temp;
        dfs(result, temp, s, wordDict);
        return result;
    }
    
    bool isBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> hash(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(dp[j])
                {
                    string temp = s.substr(j, i - j);
                    if(hash.find(temp) != hash.end())
                        dp[i] = true;
                }
            }
        }
        
        return dp[s.length()];
    }
    void dfs(vector<string>& result, string temp, string s, vector<string>& wordDict)
    {
        if(s.length() == 0)
        {
            result.push_back(temp);
            return;
        }
        
        //不可分则直接返回
        if(!isBreak(s, wordDict))
            return;
        
        for(int i = 0; i < wordDict.size(); i++)
        {
            int n = wordDict[i].length();
            string t = s.substr(0, n);
            if(wordDict[i] == t)
            {
                int l = temp.size();
                if(l != 0)
                {
                    temp += " ";
                }
                temp += wordDict[i];
                dfs(result, temp, s.substr(n), wordDict);
                temp = temp.substr(0, l);
            }
        }
        
        return;
    }
};
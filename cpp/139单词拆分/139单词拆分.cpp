/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/

//解答：先用dfs做，结果超时，如下：
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.length() == 0)
        {
            return true;
        }

        
        for(int i = 0; i < wordDict.size(); i++)
        {
            int n = wordDict[i].size();
            string temp = s.substr(0, n);
            if(temp == wordDict[i])
            {
                if(wordBreak(s.substr(n), wordDict))
                    return true;
            }
        }
        
        return false;
    }
    
};
*/
//解答:用dp做，dp[i]表示前i个字符能否被划分
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(dp[j] && m.find(s.substr(j, i - j)) != m.end())
                    dp[i] = true;
            }
        }
        
        return dp[s.size()];
    }
    
};
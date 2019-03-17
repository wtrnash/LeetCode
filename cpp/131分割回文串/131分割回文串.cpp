/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

*/

//解答：递归，每次分割成功一个子串后，对剩下来的子串递归分割，一直到分割完则加入结果中
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if(s.empty())
            return result;
        vector<string> path;
        solve(result, path, s, 0);
        return result;
    }
    
    void solve(vector<vector<string>>& result, vector<string>& path, string& s, int pos)
    {
        if(pos == s.length())
        {
            result.push_back(path);
            return;
        }
        
        for(int i = pos; i < s.length(); i++)
        {
            string temp = s.substr(pos, i - pos + 1);
            if(!isPalindrome(temp))
                continue;
            
            path.push_back(temp);
            solve(result, path, s, i + 1);
            path.pop_back();
        }
    }
    
    bool isPalindrome(string& s)
    {
        if(s.length() == 0)
            return false;
        int i = 0, j = s.length() - 1;
        while(i <= j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        
        return true;
    }
};
/*

给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。

示例 1:

输入: "aacecaaa"
输出: "aaacecaaa"
示例 2:

输入: "abcd"
输出: "dcbabcd"
*/

//解答：将s反转后得到r， t为 s + "#" + r。则s前面是回文的部分一定和r的最后一部分相等，问题就变成了求t的最长前缀后缀问题，所以可以用KMP的next数组做
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string t = s + "#" + r;
        vector<int> next(t.size(), 0);
        int k = 0;
        for(int i = 1; i < t.size(); i++)
        {
            while(k > 0 && t[k] != t[i])
                k = next[k - 1];
            
            if(t[k] == t[i])
                k++;
            
            next[i] = k;
        }
        
        string temp = s.substr(next[t.size() - 1]);
        reverse(temp.begin(), temp.end());
        return temp + s;
        
        
    }
};
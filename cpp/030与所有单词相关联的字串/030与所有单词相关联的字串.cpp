/*
给定一个字符串 s 和一些长度相同的单词 words。在 s 中找出可以恰好串联 words 中所有单词的子串的起始位置。

注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。

示例 1:

输入:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
输出: [0,9]
解释: 从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar" 。
输出的顺序不重要, [9,0] 也是有效答案。
示例 2:

输入:
  s = "wordgoodstudentgoodword",
  words = ["word","student"]
输出: []
*/

//解答：用一个map记录每个字串和对应出现的次数，然后遍历s，以s的每一个元素作为起始，直到以某一个元素作为起始，但后面的长度不够包含所有字串为止
//然后取出s中和字串同样长度的子串，先看map中有没有，如果没有则跳出当前循环，直接从s的下一个元素当起始继续，如果有
//则加入一个新的map，并且比较两个map中同一个字串的数量，如果第二个map中的数量超出了，也跳出该循环
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(s.empty() || words.empty())
            return result;
        map<string, int> m1;
        //建立字串和出现次数的键值对
        for(int i = 0; i < words.size(); i++)
        {
            m1[words[i]]++;
        }
        
        int m = words.size();
        int n = words[0].length();
        for(int i = 0; i <= (int)s.length() - m * n; i++)
        {
            map<string, int> m2;
            int j;
            for(j = 0; j < m; j++)
            {
                string temp = s.substr(i + j * n, n);
                if(m1.find(temp) == m1.end())
                    break;
                
                m2[temp]++;
                if(m2[temp] > m1[temp])
                    break;
            }
            if(j == m)
                result.push_back(i);
        }
        return result;
    }
        
};
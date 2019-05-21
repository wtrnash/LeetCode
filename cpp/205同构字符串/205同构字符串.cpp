/*
给定两个字符串 s 和 t，判断它们是否是同构的。

如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。

所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:

输入: s = "egg", t = "add"
输出: true
示例 2:

输入: s = "foo", t = "bar"
输出: false
示例 3:

输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。

*/

//解答：弄两个hashtable互相映射即可
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1, m2;
        if(s.length() == 0 && t.length() == 0)
            return true;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(m1.find(s[i]) == m1.end())   //不存在s到t的映射
            {
                if(m2.find(t[i]) != m2.end())   //但存在t到s的映射则返回false
                    return false;
                
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else
            {
                if(m1[s[i]] != t[i])    //映射不上
                    return false;
                if(m2.find(t[i]) == m2.end())   //不存在t到s的映射
                    return false;
            }
        }
        
        return true;
    }
};
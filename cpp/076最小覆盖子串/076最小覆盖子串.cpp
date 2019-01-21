/*
给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
*/
//解答：用数组类似哈希表，记录t中每个字符出现的次数。用滑动窗口法来找寻最短子串
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(s == "" || s.length() < t.length())
            return "";
        
        vector<int> sMap(256, 0), tMap(256, 0);
        for(int i = 0; i < t.length(); i++)     //记录t中每个字母的次数
        {
            tMap[t[i]]++;
        }
        
        string result = "";
        int left = 0, right = 0, minLength = s.length() + 1, count = 0;
        while(right < s.length())       //右边遍历到结尾
        {
            if(tMap[s[right]] > 0)  //如果当前的出现在t中
            {
                sMap[s[right]]++;
                if(sMap[s[right]] <= tMap[s[right]])    //说明其没有超出t中该字母的数量，说明是有效的
                {
                    count++;
                }
                
                while(count == t.length())  //找到包含T所有字符的子串后
                {
                    if(right - left + 1 < minLength)    //如果更小则更新结果
                    {
                        minLength = right - left + 1;
                        result = s.substr(left, minLength);
                    }
                    
                    if(tMap[s[left]] > 0)   //为了滑动left来找到更小的。如果该字符在t中，判断该字符是否多余，如果不多余，count要减1
                    {
                        sMap[s[left]]--;
                        if(sMap[s[left]] < tMap[s[left]])
                            count--;
                    }
                    
                    left++; //往左滑
                }
            }
            
            right++;    //往右滑
        }
        
        return result;
    }
};
/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。
*/
//解答：我先采用每个到来的词与之前result里的每个数组的首个词进行对比判断是否是异位词，然后进行相应的处理。结果最后一个用例超时
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 0)
            return result;
        vector<string> temp;
        temp.push_back(strs[0]);
        result.push_back(temp);
        int j;
        for(int i = 1; i < strs.size(); i++)
        {
            temp.clear();
            for(j = 0; j < result.size(); j++)  //遍历result之前的数组，看看是否是之前的异位词
            {
                if(isGroup(result[j][0], strs[i]))
                {
                    result[j].push_back(strs[i]);
                    break;
                }
            }
            
            if(j == result.size())  //没找到则创建新的数组
            {
                temp.push_back(strs[i]);
                result.push_back(temp);
            }
        }
        
        return result;
    }


    //判断是否一组
    bool isGroup(string a, string b)
    {
        int index;
        if(a.length() != b.length())
            return false;
        for(int i = 0; i < a.length(); i++) //必须每个元素都被找到
        {
            index = b.find(a[i]);   
            if(index == -1)
                return false;
            
            b.erase(b.begin() + index); //找到后去除
        }
        
        return true;
    }
};
*/

//后来看了网上的思路，使用hash-map。因为字母异位词排序后的词是一样的，所以每个词可以对应一个数组，新的词直接根据key加入数组即可
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 0)
            return result;
        unordered_map <string, vector<string>> m;
        for(int i = 0; i < strs.size();  i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            m[temp].push_back(strs[i]);
        }
        
        for(auto v: m)
        {
            result.push_back(v.second);
        }
        
        return result;
    }
};
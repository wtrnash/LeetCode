/*
给定一个单词列表和两个单词 word1 和 word2，返回列表中这两个单词之间的最短距离。

示例:
假设 words = ["practice", "makes", "perfect", "coding", "makes"]

输入: word1 = “coding”, word2 = “practice”
输出: 3
输入: word1 = "makes", word2 = "coding"
输出: 1
注意:
你可以假设 word1 不等于 word2, 并且 word1 和 word2 都在列表里。

*/

//解答：分别记录word1和word2最近一次的索引，并和结果比较看距离是否更短，更短则更新
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1, index2 = -1;
        int result = words.size();
        for(int i = 0; i < words.size(); i++)
        {
            if(words[i] == word1)
            {
                index1 = i;
                
                if(index2 != -1)
                {
                    int d = abs(index2 - index1);
                    if(d < result)
                        result = d;
                }
            }
                
            
            if(words[i] == word2)
            {
                index2 = i;
                if(index1 != -1)
                {
                    int d = abs(index2 - index1);
                    if(d < result)
                        result = d;
                }
            }
          
        }
        
        return result;
    }
};
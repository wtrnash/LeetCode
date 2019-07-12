/*
给定一个单词列表和两个单词 word1 和 word2，返回列表中这两个单词之间的最短距离。

word1 和 word2 是有可能相同的，并且它们将分别表示为列表中两个独立的单词。

示例:
假设 words = ["practice", "makes", "perfect", "coding", "makes"].

输入: word1 = “makes”, word2 = “coding”
输出: 1
输入: word1 = "makes", word2 = "makes"
输出: 3
注意:
你可以假设 word1 和 word2 都在列表里。

*/
//解答：类似243题，只是存在一样的单词，所以在word2更新结果的时候要判断下是否是一样的单词，一样的单词则只在word1的index改变时更新
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int result = n;
        int index1 = -1;
        int index2 = -1;
        for(int i = 0; i < n; i++)
        {
            if(word1 == words[i])
            {
                index1 = i;
                if(index2 != -1)
                {
                    result = min(result, abs(index1 - index2));
                }
            }
            
            if(word2 == words[i])
            {
                index2 = i;
                if(index1 != -1 && word1 != word2)
                {
                    result = min(result, abs(index1 - index2));
                }                
            }
        }
        
        return result;
    }
};
/*
请设计一个类，使该类的构造函数能够接收一个单词列表。然后再实现一个方法，该方法能够分别接收两个单词 word1 和 word2，并返回列表中这两个单词之间的最短距离。您的方法将被以不同的参数调用 多次。

示例:
假设 words = ["practice", "makes", "perfect", "coding", "makes"]

输入: word1 = “coding”, word2 = “practice”
输出: 3
输入: word1 = "makes", word2 = "coding"
输出: 1
注意:
你可以假设 word1 不等于 word2, 并且 word1 和 word2 都在列表里。
*/
//解答：用哈希表记录各个单词出现的下标，等输入后二重循环进行比较记录最小值即可
#include <vector>
#include <string>
using namespace std;
class WordDistance {
public:
    WordDistance(vector<string>& words) {
       for(int i = 0; i < words.size(); i++)
       {
           m[words[i]].push_back(i);
       }
    }
    
    int shortest(string word1, string word2) {
        int result = INT_MAX;
        for(int i = 0; i < m[word1].size(); i++)
        {
            for(int j = 0; j < m[word2].size(); j++)
            {
                result = min(result, abs(m[word1][i] - m[word2][j]));
            }
        }
        
        return result;
    }
private:
    unordered_map<string, vector<int>> m;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
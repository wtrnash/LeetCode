/*

说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。
*/

//解答：用bfs做。
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size() == 0)
            return 0;
        if(beginWord == endWord)
            return 1;
        map<string, int> m;
        map<string, int> result;
        queue<string> q;
        for(int i = 0; i < wordList.size(); i++)
        {
            m[wordList[i]] = 1;
        }
        
        result[beginWord] = 1;
        q.push(beginWord);
        while(!q.empty() && m.size() != 0)
        {
            string now = q.front();
            q.pop();
            int num = result[now];
            for(int i = 0; i < now.size(); i++)
            {
                string temp = now;
                for(char c = 'a'; c <= 'z'; c++)
                {
                    if(temp[i] == c)
                        continue;
                    else
                        temp[i] = c;
                    
                    if(m.find(temp) != m.end())
                    {
                        if(temp == endWord)
                        {
                            return num + 1;
                        }
                        
                        q.push(temp);
                        result[temp] = num + 1;
                        m.erase(temp);
                    }
                }
            }
        }
        
        return 0;
        
    }
};
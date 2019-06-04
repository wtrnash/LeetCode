/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: k = 3, n = 7
输出: [[1,2,4]]
示例 2:

输入: k = 3, n = 9
输出: [[1,2,6], [1,3,5], [2,3,4]]

*/

//解答：dfs做
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> s;
        vector<int> temp;
        dfs(s,temp, k, n, 1);
        return vector<vector<int>> (s.begin(), s.end());
    }
    
    void dfs(set<vector<int>>& s, vector<int> result, int k, int n, int pos)
    {
        if(result.size() > k)
            return;
        if(n < 0)
            return;
        if(n == 0)
        {
            if(result.size() == k)
            {
                s.insert(result);
            }
            
            return;
        }
        
        for(int i = pos; i <= 9; i++)
        {
            result.push_back(i);
            dfs(s, result, k, n - i, i + 1);
            result.pop_back();
        }
    }
};
/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
*/
// 解答：相比39题，这题主要是每个元素只能用一次，所以递归的时候start设置要加1。另外还要考虑有相同的元素导致结果重复的问题。
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector< vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(result, temp, candidates, target, 0);
        return result;
    }
    
    void dfs(vector<vector <int>>& result, vector<int> temp, vector<int>& candidates, int target, int start)
    {
        if(target < 0)
            return;
        if(target == 0)
        {
            result.push_back(temp);
            return;
        }
        for(int i = start; i < candidates.size(); i++)
        {
            if(i > start && candidates[i] == candidates[i - 1]) //去除同一循环内的重复元素
            {
                continue;
            }
            
            temp.push_back(candidates[i]);
            dfs(result, temp, candidates, target - candidates[i], i + 1);
            temp.pop_back();
            
        }
    }
};
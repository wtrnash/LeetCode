/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

//解答：利用深搜，递归进行搜索所有可能的组合，如果当前和大于target则返回，等于则将该组合压入结果，并传入start来避免选择重复的数
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    
    void dfs(vector<vector<int>>& result, vector<int>& candidates, vector<int>& temp, int target, int start)
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
            temp.push_back(candidates[i]);
            dfs(result, candidates, temp, target - candidates[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector <int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        dfs(result, candidates, temp, target, 0);
        return result;
    }
};
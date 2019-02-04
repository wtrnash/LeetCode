/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
//解答：dfs做，可以先排序，然后当前元素和上一个相同时不加入当前元素数组来防止重复
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        result.push_back(temp);
        dfs(result, temp, nums, 0);
        return result;
    }
    
    void dfs(vector<vector <int>>& result, vector<int>& temp, vector<int>& nums, int start)
    {
        if(start == nums.size())
            return;
        
        for(int i = start; i < nums.size(); i++)
        {
            if(i > start && nums[i] == nums[i - 1])  //去除重复的元素
                continue;
            
            temp.push_back(nums[i]);
            result.push_back(temp);
            dfs(result, temp, nums, i + 1);
            temp.pop_back();
        }
    }
};
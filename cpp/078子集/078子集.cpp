/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

//解答：用dfs深搜做。每次递归时，都将当前的数组加入result。并用变量pos防止重复

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector <int>> result;
        vector<int> temp;
        result.push_back(temp);
        add(result, temp, nums, 0);
        return result;
        
    }
    
    void add(vector<vector <int>> &result, vector<int>& temp, vector<int>& nums, int pos)
    {
        if(pos == nums.size())
            return;
        
        for(int i = pos; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            result.push_back(temp);
            add(result, temp, nums, i + 1);
            temp.pop_back();
        }
    }
};
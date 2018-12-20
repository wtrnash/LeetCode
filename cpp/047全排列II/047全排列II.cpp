/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

//解答：类似046题，主要需要去重，所以先在结果放在set中，再转化为vector返回结果
#include<iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> result;
        perm(result, nums, 0, nums.size() - 1);
        return vector<vector<int>> (result.begin(), result.end());
    }
    
    void perm(set<vector<int>>& result, vector<int> nums, int start, int end)
    {
        if(start >= end)
        {
            result.insert(nums);
            return;
        }
        
        for(int i = start; i <= end; i++)
        {
            swap(nums[start], nums[i]);
            perm(result, nums, start + 1, end);
            swap(nums[start], nums[i]);
        }
    }
};
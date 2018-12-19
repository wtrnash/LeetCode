/*
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
//解答：用递归进行，每次交换两个元素，使得能返回所有的全排列
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        perm(result, nums, 0, nums.size() - 1); //递归
        return result;
    }
    
    void perm(vector<vector<int>>& result, vector<int> nums, int begin, int end)
    {
        if(begin >= end)
        {
            result.push_back(nums);
            return;
        }
        
        for(int i = begin; i <= end; i++)
        {
            swap(nums[begin], nums[i]);
            perm(result, nums, begin + 1, end);     //换后的第一个元素不再进入后续的交换
            //swap(nums[begin], nums[i]);

        }
    }

};
/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

//解答：用二分搜索，然后比较相邻的元素确定首尾位置
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size() == 0)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int start = -1;
        int end = -1;
        
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(target == nums[mid])
            {
                end = start = mid;
                while(start - 1 >= 0 && nums[start - 1] == target)
                    start--;
                 while(end + 1 < nums.size() && nums[end + 1] == target)
                    end++;
                break;
            }
            else if(target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            
        }
        
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};
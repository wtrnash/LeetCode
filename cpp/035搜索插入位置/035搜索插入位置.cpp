/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0
*/

//解答：先处理size为0，小于最小值大于最大值的边界情况，然后用二分法进行寻找，找到直接返回坐标，没找到时low比high大了，则返回high+1的坐标即可
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        
        int low = 0;
        int high = nums.size() - 1;
        if(target < nums[low])
            return 0;
        if(target > nums[high])
            return nums.size();
        int mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return high + 1;
    }
};
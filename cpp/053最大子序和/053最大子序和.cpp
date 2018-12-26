/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

//解答：记录当前和，如果当前和小于0，则会对后面的起副作用，所以重新从0开始计
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int current = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            current += nums[i];
            if(current > max)
                max = current;
            if(current < 0)
                current = 0;
        }
        
        return max;
    }
};
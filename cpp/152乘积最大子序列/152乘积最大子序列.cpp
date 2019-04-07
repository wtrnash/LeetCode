/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

*/

//解答：记录最小和最大的数字，如果来的是负数，则交换两者，比较当前的和当前的乘以最小或最大的小或大，记录最大值。
#include <vector>
#include <cmath>
#define INT_MIN -2147483648
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int minNum = 1;
        int maxNum = 1;
        int result = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0)         //小于0则交换最小最大
            {
                int temp = maxNum;
                maxNum = minNum;
                minNum = temp;
            }
            
            maxNum = max(maxNum * nums[i], nums[i]);
            minNum = min(minNum * nums[i], nums[i]);
            
            result = max(result, maxNum);
            
        }
        
        return result;
    }
};
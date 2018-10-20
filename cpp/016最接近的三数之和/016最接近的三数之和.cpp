/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

//解答：和015三数之和类似的套路，遍历第一个数，后面两个数首尾相加，往中间靠，用一个变量记录最接近的三个数之和 
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result;
        int temp;
        int j, k;
        sort(nums.begin(), nums.end());
        result = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); i++)
        {
            temp = target - nums[i];
            j = i + 1;
            k = nums.size() - 1;
            while(j < k)
            {
                if(nums[j] + nums[k] == temp)
                {
                    return nums[i] + nums[j] + nums[k];
                }
                else if(nums[j] + nums[k] < temp)
                {
                    if(abs(temp - nums[j] - nums[k]) < abs(result - target))
                        result = nums[i] + nums[j] + nums[k];
    
                    j++;
                }
                else
                {
                    if(abs(temp - nums[j] - nums[k]) < abs(result - target))
                         result = nums[i] + nums[j] + nums[k];
                    
                    k--;
                }
            }
        }
        
        return result;
    }
};
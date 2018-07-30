/*
题目：
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
例如：
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

/*
解题思路:
用一个二重循环，先遍历数组中所有元素，遍历当前元素时，再遍历数组中余下的元素，
逐个相加判断是否和目标相等，相等则返回对应元素下标。
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target){
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }
    }
};
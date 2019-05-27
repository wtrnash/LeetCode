/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

*/

//解答：用start,end来表示连续的子串下标。如果加上当前end比s小，则end++。否则记录当前result，然后start++。
#include <cmath>
#include <vector>
#define INT_MAX 2147483647
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT_MAX;
        int start = 0;
        int temp = 0;
        int end = 0;
        int n = nums.size();
        while(end < n)
        {
            if(nums[end] >= s)
                return 1;
            if(temp + nums[end] >= s)
            {
                result = min(end - start + 1, result);
                temp -= nums[start];
                start++;
            }
            else
            {
                temp += nums[end];
                end++;
            }
        }
        
        if(result == INT_MAX)
            return 0;
        
        return result;
    }
};
/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

示例 1:

输入: nums = [1,2,3,1], k = 3
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1
输出: true
示例 3:

输入: nums = [1,2,3,1,2,3], k = 2
输出: false
*/
//解答：直接二重循环会超时，利用hashmap记录上一个元素的下标，当存在hashmap时和当前下标做比较看是否于等于k即可
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() <= 1)
            return false;
        unordered_map <int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
           if(m.find(nums[i]) != m.end())
           {
               if(i - m[nums[i]] <= k)
                   return true;
           }
            
            m[nums[i]] = i;
        }
        
        return false;
    }
};
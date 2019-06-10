/*
给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。

示例 1:

输入: nums = [1,2,3,1], k = 3, t = 0
输出: true
示例 2:

输入: nums = [1,0,1,1], k = 1, t = 2
输出: true
示例 3:

输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false

*/

//解答：利用set，存储最近的k个元素的值，如果k个中存在大于nums[i] - t的最小元素且该元素-nums[i] <= t，则存在。 要用long存储元素，不然会越界。
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() <= 1)
            return false;
        set<long> s;
        for(int i = 0; i < nums.size(); i++)
        {
            auto it = s.lower_bound(nums[i] - long(t));
            if(it != s.end() && *it - nums[i] <= t)
                return true;
            s.insert(nums[i]);
            if(s.size() > k)
                s.erase(nums[i - k]);
        }
        return false;
    }
};
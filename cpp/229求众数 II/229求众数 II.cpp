/*
给定一个大小为 n 的数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。

说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1)。

示例 1:

输入: [3,2,3]
输出: [3]
示例 2:

输入: [1,1,1,3,3,2,2,2]
输出: [1,2]

*/

//利用hash表记录每个元素出现次数，再和n/3做比较
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(nums[i]) != m.end())
            {
                m[nums[i]]++;
            }
            else
                m[nums[i]] = 1;
        }
        
        int n = nums.size() / 3;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if(it->second > n)
                result.push_back(it->first);
        }
        
        return result;
    }
};
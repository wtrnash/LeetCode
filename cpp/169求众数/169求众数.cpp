/*
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

*/

//解答：遍历一遍，将数字和对应数字出现的次数记录在哈希表中，再遍历取最大值
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(nums[i]) != m.end())
            {
                m[nums[i]]++;
            }
            else
                m[nums[i]] = 1;
        }
        
        int result = m.begin()->first;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if(it->second > m[result])
                result = it->first;
        }
        
        return result;
        
    }
};


/*
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

*/

//解答：先排序，然后依次判断当前是否等于前一个+1，记录当前的序列长度，到不为当前序列后，和最大的进行比较并更新。但要注意判断相等的情况,相等则continue
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int maxCount = 1;
        int currentCount = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1] + 1)
            {
                currentCount++;
            }
            else if(nums[i] == nums[i - 1])
                continue;
            else
            {
                if(currentCount > maxCount)
                    maxCount = currentCount;
                
                currentCount = 1;
            }
        }
        
        if(currentCount > maxCount)
            maxCount = currentCount;
        
        return maxCount;
    }
};

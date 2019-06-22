/*
给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

示例 1:

输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
示例 2:

输入: [0,2,3,4,6,8,9]
输出: ["0","2->4","6","8->9"]
解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。
*/
//解答：遍历一遍，比较和前一个元素是否是连续即可，注意处理首尾
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() == 0)
            return result;
        int start;
        int end;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
            {
                start = nums[i];
                end = nums[i];
            }
            else
            {
                if(nums[i] == nums[i - 1] + 1)
                {
                    end = nums[i];
                }
                else
                {
                    if(start == end)
                    {
                        result.push_back(to_string(start));
                    }
                    else
                    {
                        result.push_back(to_string(start) + "->" + to_string(end));
                    }
                    
                    start = nums[i];
                    end = nums[i];
                }
            }                   
            
        }
        //处理最后一个
        if(start == end)
        {
            result.push_back(to_string(start));
        }
        else
        {
            result.push_back(to_string(start) + "->" + to_string(end));
        }
        return result;
                    
        
    }
};

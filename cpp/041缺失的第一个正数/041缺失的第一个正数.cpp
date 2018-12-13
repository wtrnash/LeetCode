/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/

//由于时间复杂度为O（n)，不能用排序。所以采用原地交换的方式，让数组第i个位置存放的数为i+1。这样再遍历一遍时返回不存放i+1的那个位置i即可
#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)
            return 1;
        int temp;
        for(int i = 0; i < nums.size();)
        {
            if(nums[i] - 1 >= 0 && nums[i] - 1 < nums.size() && nums[i] != nums[nums[i] - 1])   //如果含有的元素在数组范围内，且其所在位置不合法，就交换，并不增加i，可能换过来的元素也要换位置
            {
                 temp = nums[nums[i] - 1];
                 nums[nums[i] - 1] = nums[i];
                 nums[i] = temp;
            }
            else
            {
                i++;    
            }
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] - 1 != i)
                return i + 1;
        }
        
        return nums[nums.size() - 1] + 1;
        
    }
};
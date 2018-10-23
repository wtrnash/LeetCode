/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/

//解答： 类似三数之和的做法，只是排序后，前面是一个二重循环确定前两个数，然后用首尾指针确定后面两个数，我这里用set进行了重复判断
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector <int>> result;
        int temp, left, right;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {            
                temp = target - nums[i] - nums[j];
                left = j + 1;
                right = nums.size() - 1;
                while(left < right)
                {
                    if(nums[left] + nums[right] == temp)
                    {
                        vector<int> v = {nums[i], nums[j], nums[left], nums[right]};
                        result.insert(v);
                        left++;
                        right--;
                    }
                    else if(nums[left] + nums[right] < temp)
                        left++;
                    else
                        right--;
                }
            }
        }
        
        vector<vector <int>> v;
        v.assign(result.begin(), result.end());
        return v;
    }
};
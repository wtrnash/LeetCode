/*

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4
*/

//解答：先排序，然后再遍历一遍找到和后面不相等的或最后一个元素
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int n = nums.size();
        while(i < n - 1)
        {
            if(nums[i] != nums[i + 1])
                return nums[i];
            
            i += 2;
        }
        
        return nums[n - 1];
    }
};
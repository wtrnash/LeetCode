/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,3,2]
输出: 3
示例 2:

输入: [0,1,0,1,0,1,99]
输出: 99
*/
//解答：利用位运算，使得3次出现得可以消除为0
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            one = (nums[i] ^ one) & ~two;
            two = (nums[i] ^ two) & ~one;
        }
        
        return one;
    }
};
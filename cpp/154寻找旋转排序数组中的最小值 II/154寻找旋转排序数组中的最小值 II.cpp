/*

假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

注意数组中可能存在重复的元素。

示例 1：

输入: [1,3,5]
输出: 1
示例 2：

输入: [2,2,2,0,1]
输出: 0
说明：

这道题是 寻找旋转排序数组中的最小值 的延伸题目。
允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
*/

//解答：用二分法，如果left比mid大，说明最小值一定在前半段，如果mid比right大，说明最小值在后半段，不然就right--
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int m;
        while(l < r)
        {
            m = (l + r) / 2;
            if(nums[l] > nums[m])
            {
                r = m;
            }
            else if(nums[m] > nums[r])
            {
                l = m + 1;
            }
            else{
                r--;
            }
        }
        
        return nums[l];
    }
};
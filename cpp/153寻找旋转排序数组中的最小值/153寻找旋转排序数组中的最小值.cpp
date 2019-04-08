/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0

*/
//解答：利用二分法
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min_num = nums[0];
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(nums[low] < nums[mid])   //前半部分按顺序
            {
                if(nums[low] < min_num)
                {
                    min_num = nums[low];
                    
                }
                low = mid + 1;
            }
            else
            {
                if(nums[high] < min_num)
                {
                    min_num = nums[high];
                }
                if(nums[mid] < min_num)
                {
                    min_num = nums[mid];
                }
                high = mid - 1;
            }
        }
        
        return min_num;
    }
};
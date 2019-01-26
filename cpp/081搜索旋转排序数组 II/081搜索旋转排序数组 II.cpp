/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

示例 1:

输入: nums = [2,5,6,0,0,1,2], target = 0
输出: true
示例 2:

输入: nums = [2,5,6,0,0,1,2], target = 3
输出: false
进阶:

这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
*/
//解答：确定哪边是有序的。相比之前不重复的033，就是要判断相等时是全部重复的有序状态，还是无序状态，再分别处理即可。

#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] < nums[high])
            {
                if(nums[high] < target || target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if(nums[mid] == nums[high])    //等于可能有序也可能无序
            {
                bool isSorted = true;
                for(int j = mid; j < high; j++)
                {
                    if(nums[j] != nums[j + 1])
                    {
                        isSorted = false;
                        break;
                    }
                }
                
                if(isSorted)
                {
                    if(nums[high] < target || target < nums[mid])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                   if(target < nums[low] || target > nums[mid])
                   {
                       low = mid + 1;
                   }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
            else
            {
               if(target < nums[low] || target > nums[mid])
               {
                   low = mid + 1;
               }
                else
                {
                    high = mid - 1;
                }
            }
        }
        
        return false;
    }
};
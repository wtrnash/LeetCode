/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。

*/

//解答：利用一个count进行计数，遇到重复超过2次的， 把后面的全部往前移，并且当前索引不自增，整个长度length-1。遇到不一样的，则更新count为1
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();
        int length = nums.size();
        int count = 1;
        int i = 1;
        while(i < length)
        {
            if(nums[i] == nums[i - 1])
            {
                count++;
                if(count > 2)
                {
                    for(int j = i; j < length - 1; j++)
                    {
                        nums[j] = nums[j + 1];
                    }
                    length--;
                }
                else
                    i++;
            }
            else
            {
                count = 1;
                i++;
            }
                
        }
        
        return length;
    }
};
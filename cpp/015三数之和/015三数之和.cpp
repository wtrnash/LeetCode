/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

//用暴力法，O(n^3)直接找所有的和为0的三元组，再和之前已经和为0的三元组比较判断是否重复，结果时间超出：
/*
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                for(int k = j + 1; k < nums.size(); k++)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end()); //排序
                        bool isSame = false;
                        for(int m = 0; m < result.size(); m++)
                        {
                            if(result[m][0] == temp[0] && result[m][1] == temp[1] && result[m][2] == temp[2])
                            {
                                isSame = true;
                                break;
                            }
                        }
                        
                        if(!isSame)
                            result.push_back(temp);
                    }
                }
            }
        }
        
        return result;
    }
};
*/

//解答，先对整个数组排序，确定前两个数字后，第三个数为前两个数和的负数，然后使用二分法在后面寻找，这样提升了速度，时间复杂度在O(n^2 * logn)，能够通过
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int num, high, mid, low;
        sort(nums.begin(), nums.end());   
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                num = -(nums[i] + nums[j]); //第三个数
                low = j + 1;
                high = nums.size() - 1;
                while(low <= high)  //二分法寻找
                {
                    mid = (low + high) / 2;
                    if(num == nums[mid])
                    {
                    
                        vector<int> temp = {nums[i], nums[j], num};
                        sort(temp.begin(), temp.end());
                        bool isSame = false;
                        for(int m = 0; m < result.size(); m++)  //判断是否有重复的
                        {
                            if(result[m][0] == temp[0] && result[m][1] == temp[1] && result[m][2] == temp[2])
                            {
                                isSame = true;
                                break;
                            }
                        }
                        
                        if(!isSame)
                            result.push_back(temp);
                        break;
                    }
                    else if(num < nums[mid])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
      
            }
        }
        
        return result;
    }
};


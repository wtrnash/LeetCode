/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。
*/

//解答：我一开始尝试通过循环，穷举所有情况，结果时间超时，如下：

#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        vector<int> counts(nums.size(), nums.size());
        counts[nums.size() - 1] = 0;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(i + nums[i] >= nums.size() - 1)
            {
                counts[i] = 1;
                continue;
            }
            
            int min = nums.size() - 1 - i;
            for(int j = 1; j <= nums[i]; j++)
            {
                if(1 + counts[i + j] < min)
                    min = 1 + counts[i + j];
            }
            counts[i] = min;
        }
        
        return counts[0];
        
    }

};
*/

//后来看网上解答，还是用贪心的算法，每步都争取能跳跃最远的范围，O(n)的数量级就可以解决该问题。
class Solution {
public:
    int jump(vector<int>& nums) {
       int last = 0;    //记录上一步最远的范围
       int current = 0; //记录这一步最远的范围
       int result = 0;  //跳的步数
       for(int i = 0; i < nums.size(); i++) 
       {
           if(i > last) //当前i已经大于上一步的最远范围，则更新步数和当前的范围
           {
               last = current;
               result++;
           }
           current = current < i + nums[i] ? i + nums[i] : current; //如果i能覆盖的最远范围比当前远，则更新
       }
        
        return result;
        
    }
    
  

};
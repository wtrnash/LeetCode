/*
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口 k 内的数字。滑动窗口每次只向右移动一位。

返回滑动窗口最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
注意：

你可以假设 k 总是有效的，1 ≤ k ≤ 输入数组的大小，且输入数组不为空。

进阶：

你能在线性时间复杂度内解决此题吗？

*/
//解答：利用单调队列来做
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0 || k == 0)
            return {};
        vector<int> result;
        deque<int> q;
        for(int i = 0; i < k; i++)
        {
            while(!q.empty() && q.back() < nums[i])    //单调队列。比如5 3 2 1，要压进4，那么滑动到3 2 1的时候4依旧是最大的，所以可以弹出3 2 1
                    q.pop_back();
                
            q.push_back(nums[i]);
        }
        
        result.push_back(q.front());
        
        for(int i = k; i < nums.size(); i++)
        {
            if(!q.empty() && q.front() == nums[i - k])  //如果滑出窗口的元素即为最大元素则弹出
                q.pop_front();
            
           while(!q.empty() && q.back() < nums[i])   //加入该元素
                    q.pop_back();
                
            q.push_back(nums[i]);
            
            result.push_back(q.front());
        }
        
        return result;
    }
};
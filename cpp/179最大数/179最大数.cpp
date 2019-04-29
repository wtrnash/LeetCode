/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。

示例 1:

输入: [10,2]
输出: 210
示例 2:

输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/
//解答：写一个比较函数，比较a+b和b+a的大小即可
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool static compare(int a, int b)
    {
        if(a == b)
            return false;
        string ta = to_string(a);
        string tb = to_string(b);
        string x = ta + tb;
        string y = tb + ta;
        return x > y;
        
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string result;
        if(nums[0] == 0)
            return "0";
        for(int i = 0; i < nums.size(); i++)
        {
            result += to_string(nums[i]);
        }
        
        return result;
    }
};
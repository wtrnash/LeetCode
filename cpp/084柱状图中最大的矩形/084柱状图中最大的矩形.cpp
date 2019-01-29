/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 
（图见leetcode)


以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

 
（图见leetcode)


图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

 

示例:

输入: [2,1,5,6,2,3]
输出: 10
*/
//解答：利用递增栈，这样弹出时可以保证该元素是从右往左里高度最小的元素，从而可以正确计算面积
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;   //维持一个递增栈
        int maxArea = 0;
        heights.push_back(0);   //最后放一个0进去，为了能弹出所有元素
        int i = 0;
        int n = heights.size();
        int temp;
        int currentArea;
        while(i < n)
        {
            if(s.empty() || heights[s.top()] <= heights[i])  //递增的则压栈
                s.push(i++);
            else
            {
                temp = s.top();
                s.pop();
                currentArea = heights[temp] * (s.empty()? i: i - s.top() - 1);
                maxArea = maxArea > currentArea? maxArea:currentArea;
            }
        }
        
        return maxArea;
        
    }
};
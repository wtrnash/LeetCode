/*
给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例:

输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
输出: 6
*/

//解答：利用84题的知识，这题相当于是多层的求柱状图中的最大矩形。每次从第一层开始求矩形，然后逐层累加。要注意的是遇到0，该列的高度直接清0
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)
        {
            return 0;
        }
        
        int m = matrix[0].size();
        if(m == 0)
        {
            return 0;
        }
        
        vector<int> heights(m, 0);
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j] += 1;
            }
            result = max(result, largestRectangleArea(heights));
            
        }
        
        return result;
        
    }
    
    int largestRectangleArea(vector<int> heights)   //递增栈求柱状图最大的矩形面积
    {
        heights.push_back(0);
        int result = 0;
        stack<int> st;
        int i = 0;
        int n = heights.size();
        int length;
        int temp;
        while(i < n)
        {
            if(st.empty() || heights[st.top()] <= heights[i])
                st.push(i++);
            else
            {
                temp = st.top();
                st.pop();
                length = st.empty()? i : i - st.top() - 1;
                result = max(result, length * heights[temp]);
            }
        }
        
        return result;
    }
    
};
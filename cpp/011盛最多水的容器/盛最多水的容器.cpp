/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
*/

//解答，先用暴力法做，即遍历以每个做起始端点和末尾端点的，时间复杂度O(n^2)，这样能完成，但速度会比较慢
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        for(int i = 0; i < height.size(); i++)
        {
            for(int j = i + 1; j < height.size(); j++)
            {
                int temp = (j - i) * (height[i] > height[j]? height[j] : height[i]);
                if(temp > result)
                    result = temp;
            }
        }
        
        return result;
    }
};

*/

//下述方法时间复杂度只为o(N)，即首尾同时指向开始和末尾，然后每次将较短那根往里移动。因为面积受限于较短那根
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int current;
        int i, j;
        for(i = 0, j = height.size() - 1; i < j;)
        {
            current = (j - i) * (height[i] > height[j] ?height[j]: height[i]);
            if(current > result)
                result = current;
            
            if(height[i] > height[j])
                j--;
            else
                i++;
        }
        
        return result;
    }
};
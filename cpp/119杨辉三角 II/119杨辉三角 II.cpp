/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？
*/

//解答：类似118,，只是把最后一行输出。然后这里从第0行开始
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;
        vector<int> temp;
        
        if(rowIndex == 0)
        {
            temp.push_back(1);
            return temp;
        }
        
        result.push_back(temp);
        for(int i = 2; i <= rowIndex + 1; i++)
        {
            temp.clear();
            for(int j = 0; j < i; j++)
            {
                if(j == 0 || j == i - 1)
                    temp.push_back(1);
                else
                {
                    temp.push_back(result[i - 2][j - 1] + result[i - 2][j]);
                }
            }
            
            result.push_back(temp);
        }
        
        return temp;
    }
};
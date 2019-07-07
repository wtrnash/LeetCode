/*
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。
示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。

*/

//解答：判断属不属于某行的范围，然后在每行分别二分
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0)
            return false;
        int m = matrix[0].size();
        if(m == 0)
            return false;
        
        for(int i = 0; i < n; i++)
        {
            if(target < matrix[i][0])
                return false;
            if(target > matrix[i][m - 1])
                continue;
            if(binarySearch(matrix[i], target))
                return true;
        }
        return false;
        
    }
    
    bool binarySearch(vector<int> v, int target)
    {
        if(v.size() == 0)
            return false;
        int left = 0;
        int right = v.size() - 1;
        int mid;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if(target == v[mid])
                return true;
            else if(target > v[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        
        return false;
    }
};
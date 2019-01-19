/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false
*/

//解答：我这里使用了两个二分，整个大矩阵在行上二分。然后行上对列进行二分
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        if(n == 0)
            return false;
        int low = 0, high = m - 1;
        int mid, rowMid;
        int left, right;
        while(low <= high)  //对行二分
        {
            mid = (low + high) / 2;
            left = 0;
            right = n - 1;
            if(matrix[mid][left] == target)
                return true;
            else if(matrix[mid][left] > target)
            {
                high = mid - 1;
            }
            else
            {
                if(matrix[mid][right] == target)
                    return true;
                else if(matrix[mid][right] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    while(left <= right)    //对列二分
                    {
                        rowMid = (left + right) / 2;
                        if(matrix[mid][rowMid] == target)
                            return true;
                        else if(matrix[mid][rowMid] < target)
                            left = rowMid + 1;
                        else
                            right = rowMid - 1;
                    }
                    
                    return false;
                }
                
            }
        }
        
        return false;
    }
};
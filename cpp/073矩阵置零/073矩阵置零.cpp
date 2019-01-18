/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例 1:

输入: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:

输入: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:

一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？
*/

//解答：我这里使用了O(m+n)的额外空间， 先遍历矩阵，如果matrix[i][j]为0，则row[i]和column[j]等下都要置为零
#include <vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> column(n, false);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(row[i])
            {
                for(int j = 0; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        
        for(int j = 0; j < n; j++)
        {
            if(column[j])
            {
                for(int i = 0; i < m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
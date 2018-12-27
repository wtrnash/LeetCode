/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

//解答：就按照螺旋的方式，记录行的开始和结束以及列的开始和结束，每次依照先从开始行的开始列到结束列，开始行+1，再从结束列的开始行到结束行，结束列-1，再从结束行的结束列到开始列
//结束行+1，再从开始列的结束行到开始行，开始列+1。依次进行，每次判断是否越界
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0)
            return result;
        
        int startRow = 0;
        int endRow = matrix.size() - 1;
        int startColumn = 0;
        int endColumn = matrix[0].size() - 1;
        while(startRow <= endRow && startColumn <= endColumn)
        {
            for(int i = startColumn; i <= endColumn; i++)
            {
                result.push_back(matrix[startRow][i]);
            }
            
            startRow++;
            
            if(startRow > endRow)
                break;
            
            for(int i = startRow; i <= endRow; i++)
            {
                result.push_back(matrix[i][endColumn]);
            }
            
            endColumn--;
            
            if(startColumn > endColumn)
                break;
            
            for(int i = endColumn; i >= startColumn; i--)
            {
                result.push_back(matrix[endRow][i]);
            }
            
            endRow--;
            
            for(int i = endRow; i >= startRow; i--)
            {
                result.push_back(matrix[i][startColumn]);
            }
            
            startColumn++;
            
       
        }
        
        return result;
    }
};
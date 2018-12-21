/*
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

//解答：发现旋转的元素规律为matrix[x][y] = matrix[n - 1 - y][x]， 但要防止一个元素重复旋转，所以加一个判别数组，判断是否被访问过
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        int tempX;
        int x;
        int y;
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));     //判断是否旋转过
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!isVisited[i][j])
                {
                     //一次旋转4个数字
                 temp = matrix[i][j];
                 x = i;
                 y = j;
                 for(int k = 0; k < 3; k++)
                 { 
                    isVisited[x][y] = true;
                    matrix[x][y] = matrix[n - 1 - y][x];
                    tempX = x;
                    x = n - 1 - y;
                    y = tempX;
                 }
                isVisited[x][y] = true;
                 matrix[x][y] = temp;
                }
            }
        }
    }
    

};
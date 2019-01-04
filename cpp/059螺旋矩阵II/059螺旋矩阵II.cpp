/*
给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
//解答：初始化矩阵后，按螺旋的顺序依次赋值即可。类似螺旋矩阵I
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector <int>> v(n, vector<int>(n, 0));
        
        int startRow = 0;
        int startColumn = 0;
        int endRow = n - 1;
        int endColumn = n - 1;
        int nums = 1;
        while(startRow <= endRow && startColumn <= endColumn)
        {
            for(int i = startColumn; i <= endColumn; i++)
            {
                v[startRow][i] = nums++;
            }
            
            startRow++;
            if(startRow > endRow)
                break;
            
            for(int i = startRow; i <= endRow; i++)
            {
                v[i][endColumn] = nums++;
            }
            
            endColumn--;
            if(startColumn > endColumn)
                break;
            
            for(int i = endColumn; i >= startColumn; i--)
            {
                v[endRow][i] = nums++;
            }
            
            endRow--;
            if(startRow > endRow)
                break;
            
            for(int i = endRow; i >= startRow; i--)
            {
                v[i][startColumn] = nums++;
            }
            
            startColumn++;
        }
        
        return v;
    }
};
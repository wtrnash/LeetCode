/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
*/

//解答：处理边界上的O,先改为*，然后找和它相连的O,全部改成*，这样剩下的O都是要变成X的，再把*的改为O即可
#include <vector>
using namespace std;
class Solution {
public:
    int m;
    int n;
    void solve(vector<vector<char>>& board) {
        m = board.size();
        if(m == 0)
            return;
        
        n = board[0].size();
        if(n == 0)
            return;
        
        //递归处理边界的O
        for(int i = 0; i < m; i++)
        {
            solve(board, i, 0);
            solve(board, i, n - 1);
        }
        
        for(int j = 0; j < n; j++)
        {
            solve(board, 0, j);
            solve(board, m - 1, j);
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
        
    }
    
    void solve(vector<vector<char>>& board, int i, int j)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;
        
        if(board[i][j] == 'O')
        {
            board[i][j] = '*';
            solve(board, i - 1, j);
            solve(board, i + 1, j);
            solve(board, i, j - 1);
            solve(board, i, j + 1);
        }
    }
    
    
};
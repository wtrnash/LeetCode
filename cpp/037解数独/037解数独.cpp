/*
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。
Note:

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。
*/

//解答：用深搜，递归+回溯，暴力填满整个数独即可
#include <vector>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);      
    }
    bool dfs(vector<vector<char>>& board, int i, int j)
    {
        if(i == 9)
            return true;
        if(j == 9)
            return dfs(board, i + 1, 0);
        if(board[i][j] != '.')
            return dfs(board, i, j + 1);
        if(board[i][j] == '.')
        {
            for(int k = 1; k <= 9; k++)
            {
                board[i][j] = '0' + k;
                if(isValidSudoku(board))
                {
                    if(dfs(board, i, j + 1))
                        return true;  
                }
               
            }
            board[i][j] = '.';
        }
        
        return false;
        
    }
    
     bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> nums(10, 0);
        //行
        for(int i = 0; i < 9; i++)
        {
            fill(nums.begin(), nums.end(), 0);
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(nums[board[i][j] - '0'] == 1)
                        return false;
                    else
                        nums[board[i][j] - '0']++;
                }
            }
        }
        
        //列
        for(int j = 0; j < 9; j++)
        {
            
            fill(nums.begin(), nums.end(), 0);
            for(int i = 0; i < 9; i++)
            {
                if(board[i][j] != '.')
                {
                    if(nums[board[i][j] - '0'] == 1)
                        return false;
                    else
                        nums[board[i][j] - '0']++;
                }
            }
        }
        
        //小矩阵
        for(int k = 0; k <= 6; k += 3)
        {
            for(int l = 0; l <= 6; l += 3)
            {
            
                fill(nums.begin(), nums.end(), 0);
                for(int i = k; i < k + 3; i++)
                {   
                    for(int j = l; j < l + 3; j++)
                    {
                        if(board[i][j] != '.')
                        {
                            if(nums[board[i][j] - '0'] == 1)
                                return false;
                            else
                                nums[board[i][j] - '0']++;
                        }
                    }


                }
            }
        }
        
        return true;
    }
};
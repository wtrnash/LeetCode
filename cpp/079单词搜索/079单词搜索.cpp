/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true.
给定 word = "SEE", 返回 true.
给定 word = "ABCB", 返回 false.
*/

//解答：利用dfs深搜做，先二重循环，找到和第一个字符一样的下标，然后再利用递归，在其的上下左右进行搜索即可
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int m;
    int n;
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() == 0)
            return false;
        m = board.size();
        if(m == 0)
            return false;
        n = board[0].size();
        if(n == 0)
            return false;
        
        vector<vector<bool>> isUsed(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0])
                {
                    isUsed[i][j] = true; 
                    if(dfs(board, word, isUsed, i, j, 1))
                        return true;
                    
                    isUsed[i][j] = false;
                }
                    
            }
        }
       
        return false;
        
    }
    
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& isUsed, int x, int y, int pos)
    {
        if(pos == word.length())
            return true;
        
        if(x - 1 >= 0 && !isUsed[x-1][y] && board[x - 1][y] == word[pos])
        {
            isUsed[x - 1][y] = true;
            if(dfs(board, word, isUsed, x - 1, y, pos + 1))
                return true;
            
            isUsed[x - 1][y] = false;
        }
        
         if(x + 1 < m && !isUsed[x+1][y] && board[x + 1][y] == word[pos])
        {
            isUsed[x + 1][y] = true;
            if(dfs(board, word, isUsed, x + 1, y, pos + 1))
                return true;
            
            isUsed[x + 1][y] = false;
        }
        
         if(y - 1 >= 0 && !isUsed[x][y - 1] && board[x][y - 1] == word[pos])
        {
            isUsed[x][y - 1] = true;
            if(dfs(board, word, isUsed, x, y - 1, pos + 1))
                return true;
            
            isUsed[x][y - 1] = false;
        }
        
         if(y + 1 < n && !isUsed[x][y + 1] && board[x][y + 1] == word[pos])
        {
            isUsed[x][y + 1] = true;
            if(dfs(board, word, isUsed, x, y + 1, pos + 1))
                return true;
            
            isUsed[x][y + 1] = false;
        }
        
    
        return false;
        
    }
};
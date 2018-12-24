/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

上图为 8 皇后问题的一种解法。（图见leetcode)

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
*/

//解答：直接用递归，在合法的位置放Q, 直到放满，结果超时
/*
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector <string>> result;
        vector<string> v(n, string(n, '.'));
        dfs(result, v, n, 0, 0, 0);
        return result;
    }
    
    void dfs(vector<vector<string>>& result, vector<string>& v, int n, int now, int x, int y)
    {
        if(now == n)
        {
            result.push_back(v);
            return;
        }
        
        if(y == n)
        {
            y = 0;
            x = x + 1;
        }
        
        for(int i = x; i < n; i++)
        {
            for(int j = y; j < n; j++)
            {
                if(noQueens(v, i, j))
                {
                    v[i][j] = 'Q';
                    dfs(result, v, n, now + 1, x, y + 1);
                    v[i][j] = '.';
                }
            }
        }
    }
    bool noQueens(vector<string> v, int i, int j)
    {
        for(int k = 0; k < v.size(); k++)
        {
            if(v[k][j] == 'Q')
                return false;
        }
        
         for(int k = 0; k < v.size(); k++)
        {
            if(v[i][k] == 'Q')
                return false;
        }
        
        for(int k = 1; i + k < v.size() && j + k < v.size(); k++)
        {
            if(v[i + k][j + k] == 'Q')
                return false;
        }
        
         for(int k = 1; i - k >= 0 && j - k >= 0; k++)
        {
            if(v[i - k][j - k] == 'Q')
                return false;
        }
        
        for(int k = 1; i + k < v.size() && j - k >= 0; k++)
        {
            if(v[i + k][j - k] == 'Q')
                return false;
        }
        
         for(int k = 1; i - k >= 0 && j + k < v.size(); k++)
        {
            if(v[i - k][j + k] == 'Q')
                return false;
        }
        
        return true;                
            
    }
};
*/

//解答：这边优化了一下递归的流程，每次只处理一排，然后用一个整型vector记录每行皇后的位置，到最后再根据格式进行输出
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector <string>> result;
        vector<int> pos(n, -1);
        dfs(result, pos, 0);
        return result;
    }
    
    void dfs(vector<vector<string>>& result, vector<int> pos, int row)
    {
        int n = pos.size();
        if(row == n)
        {
            vector<string> temp(n, string(n, '.'));
            for(int i = 0; i < n; i++)
            {
               temp[i][pos[i]] = 'Q';
            }
            
            result.push_back(temp);
            return;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(isValid(pos, row, i))
            {
                pos[row] = i;
                dfs(result, pos, row + 1);
            }
        }
        
        
    }
    
    bool isValid(vector<int> pos, int row, int column)
    {
        for(int i = 0; i < row; i++)
        {
            if(pos[i] == column || abs(row - i) == abs(pos[i] - column))
                return false;
        }
        
        return true;
    }
    
    
};
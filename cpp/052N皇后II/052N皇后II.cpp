/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。(图见leetcode)

给定一个整数 n，返回 n 皇后不同的解决方案的数量。

示例:

输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]

*/

//解答：和051一样的思路，递归，每次处理一行中的合法位置，只是最后的输出变成了整型的累加
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<int> pos(n, -1);
        dfs(result, pos, 0);
        return result;
    }
    
    void dfs(int& result, vector<int> pos, int row)
    {
        int n = pos.size();
        if(row == n)
        {
            result++;
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
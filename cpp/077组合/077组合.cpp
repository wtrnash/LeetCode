/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

//解答：使用递归完成即可。给定一个当前元素，每次只能添加当前元素以及其之后的元素。每次递归k-1，直到k等于0为止。
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector <int>> result;
        vector<int> temp;
        if(n <= 0 || k <= 0)
            return result;
        add(result, temp, 1, n, k);
        return result;
    }
    
    void add(vector< vector<int>>& result, vector<int>& temp, int now, int n, int k)
    {
        if(k == 0)
        {
            result.push_back(temp);
            return;
        }
        
        for(int i = now; i <= n; i++)
        {
            temp.push_back(i);
            add(result, temp, i + 1, n, k - 1);
            temp.pop_back();
        }
    }
};
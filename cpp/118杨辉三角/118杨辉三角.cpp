/*
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

//解答：二重循环，利用之前上一层的值得到下一层的值
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if(numRows == 0)
            return result;
        vector<int> temp = {1};
        result.push_back(temp);
        if(numRows == 1)
            return result;
        
        temp.push_back(1);
        result.push_back(temp);
        vector<int> current;
        for(int i = 3; i <= numRows; i++)
        {
            current.clear();
            current.push_back(1);
            for(int j = 0; j < temp.size() - 1; j++)
            {
                current.push_back(temp[j] + temp[j + 1]);
            }
            current.push_back(1);
            result.push_back(current);
            temp.assign(current.begin(), current.end());
        }
        
        
        return result;
        
    }
};
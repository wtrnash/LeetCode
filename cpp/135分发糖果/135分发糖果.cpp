/*

老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:

输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
示例 2:

输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
*/

//解答：用数组记录每个位置的糖果数，初始为1。从前往后遍历，如果后面的比前面的大，要更新成前面的加一。再从后往前遍历，如果前面的比后面的大，前面的也要更新
#include <vector>

using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 0)
            return 0;
        
        vector<int> count(n, 1);
        for(int i = 0; i < n - 1; i++)
        { 
            if(ratings[i + 1] > ratings[i])
            {
                count[i + 1] = count[i] + 1;
            }
        }
        
        for(int i = n - 1; i > 0; i--)
        {
            if(ratings[i] < ratings[i - 1])
            {
                count[i - 1] = max(count[i - 1], count[i] + 1);
            }
        }
        
        int num = 0;
        for(int i = 0; i < n; i++)
            num += count[i];
        
        return num;
    }
};
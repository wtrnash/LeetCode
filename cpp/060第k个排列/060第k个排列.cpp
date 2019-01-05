/*
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"
示例 2:

输入: n = 4, k = 9
输出: "2314"
*/

//解答：先排出第一个序列，然后根据K的值，每次进行一次交换直到k = 1为止。每次的交换，是从后往前找，先找到一个元素，然后和其后面比它大的最小元素做交换，然后对后面的元素
//进行升序排序即可

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        string result = "";
        for(int i = 1; i <= n; i++)
        {
            result += to_string(i);
        }
        
        while(k > 1)
        {
            for(int i = n - 1; i >= 0; i--)         //从后往前确定当前元素
            {
                bool isSwap = false;
                for(int j = n - 1; j > i; j--)      //然后与从后往前的进行比较
                {
                    if(result[i] < result[j])       //找到比它大的交换
                    {
                        swap(result[i], result[j]);
                        sort(result.begin() + i + 1, result.end());         //对后面的进行升序排序
                        isSwap = true;
                        break;
                    }
                }
                
                if(isSwap)
                    break;
            }
            k--;
        }
        
        return result;
    }
};



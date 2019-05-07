/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2:

输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
*/
//解答：如果k>=数组大小的2分之一，说明可以尽可能多地交易，就类似题122。否则如题123的推广，记录第i次买入和卖出的最大值即可
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k < 1)
            return 0;
        if(k >= prices.size() / 2)
            return greedy(prices);
        
        vector<int> buy(k, -prices[0]);
        vector<int> sell(k, 0);
        for(int i = 0; i < prices.size(); i++)
        {
            buy[0] = max(buy[0], -prices[i]);
            sell[0] = max(sell[0], buy[0] + prices[i]);
            for(int j = 1; j < k; j++)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        
        return sell[k - 1];
        
    }
    
    int greedy(vector<int>& prices)
    {
        int result = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i - 1])
                result += prices[i] - prices[i - 1];
        }
        
        return result;
    }
};
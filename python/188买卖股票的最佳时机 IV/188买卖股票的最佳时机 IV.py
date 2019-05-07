"""
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
"""
# 解答：如果k>=数组大小的2分之一，说明可以尽可能多地交易，就类似题122。否则如题123的推广，记录第i次买入和卖出的最大值即可
class Solution:
    def maxProfit(self, k: int, prices) -> int:
        if k < 1:
            return 0
        if k >= len(prices) // 2:
            return self.greedy(prices)
        
        buy = [-prices[0]] * k
        sell = [0] * k
        for p in prices:
            buy[0] = max(buy[0], -p)
            sell[0] = max(sell[0], buy[0] + p)
            for i in range(1, k):
                buy[i] = max(buy[i], sell[i - 1] - p)
                sell[i] = max(sell[i], buy[i] + p)
        
        return sell[k - 1]
        
    
    def greedy(self, prices):
        result = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                result += prices[i] - prices[i - 1]
            
        return result
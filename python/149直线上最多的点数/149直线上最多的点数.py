"""
给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

示例 1:

输入: [[1,1],[2,2],[3,3]]
输出: 3
解释:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
示例 2:

输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出: 4
解释:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
"""

# 解答：双重循环，大循环遍历一遍所有点，小的循环记录和该点在同一条直线的其他点数
# 利用哈希表，key为两个点之间x的差，y的差， value为点数。 
# Definition for a point.
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

import collections
class Solution:
    def gcd(self, a, b):
        if b == 0:
            return a
        
        return self.gcd(b, a % b)
    
    def maxPoints(self, points) -> int:
        n = len(points)
        if n == 0:
            return 0
        
        result = 1
        
        for i in range(n):
            if n - i <= result: # 不会再有更高的点数了
                break
                
            m = collections.defaultdict(int)
            same = 1
            for j in range(i + 1, n):
                a = points[j].x - points[i].x
                b = points[j].y - points[i].y
                if a == 0 and b == 0:
                    same += 1
                    continue
                
                if a == 0:
                    m[(0, 1)] += 1
                elif b == 0:
                    m[(1, 0)] += 1
                else:
                    k = self.gcd(a, b)
                    m[(a / k, b / k)] += 1
            
            result = max(result, same)
            for d in m:
                result = max(result, same + m[d])
        
        return result
            
            
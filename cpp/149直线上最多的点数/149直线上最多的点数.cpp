/*
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
*/

//解答：双重循环，大循环遍历一遍所有点，小的循环记录和该点在同一条直线的其他点数
//利用哈希表，key为两个点之间x的差，y的差， value为点数。 
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/**
 * Definition for a point.
 */ struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };
 
class Solution {
public:
     struct cmp{
        bool operator()(const Point &a, const Point &b)const
        {
            return a.x == b.x && a.y == b.y;
        }
    };
    
    struct hash_func  //hash 函数
    {
        size_t operator()(const Point &a) const
        {
             return a.x + a.y;
        }
    };

    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n == 0)
            return 0;
        
        unordered_map<Point, int, hash_func, cmp> m;
        int result = 1;
        int same;
        for(int i = 0; i < n; i++)
        {
            if(n - i <= result)
                break;
            
            m.clear();
            same = 1;
            for(int j = i + 1; j < n; j++)
            {
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                if(dx == 0 && dy == 0)  //在同一个点上
                {
                    same++;
                    continue;
                }
                
                if(dx == 0)     //横坐标相同
                {
                    m[Point(0, 1)]++;
                }
                else if(dy == 0)
                {
                    m[Point(1, 0)]++;
                }
                else
                {
                    int k = gcd(dx, dy);
                    m[Point(dx / k, dy / k)]++;
                }
                
            }
            
            result = max(result, same);
            
            for(auto it = m.begin(); it != m.end(); it++)
            {
                result = max(result, same + it->second);
            }
        }
        
        return result;
    }
    
    int gcd(int a, int b)
    {
        return b? gcd(b, a % b) : a;
    }
};
/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

//解答：先按开始前后进行升序排序。然后每个区间和后一个区间进行比较，如果当前区间的结束时间大于等于后一个区间的开始时间，再选取两个里面结束时间晚的，进行合并
//如果当前区间的结束时间小于后一个区间的开始时间，说明不重叠，则把当前区间压入新的数组。循环结束后压入最后一个区间
 
 #include <vector>
 #include <algorithm>
 using namespace std;
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
 
bool compare(Interval& i1, Interval& i2)
{
    if(i1.start == i2.start)
        return i1.end < i2.end;
    return i1.start < i2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return intervals;
        vector<Interval> v;
        sort(intervals.begin(), intervals.end(), compare);
        Interval temp(intervals[0].start, intervals[0].end);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(temp.end >= intervals[i].start)
            {
                if(temp.end < intervals[i].end)
                {
                    temp.end = intervals[i].end;
                }
                
            }
            else
            {
                v.push_back(temp);
                temp.start = intervals[i].start;
                temp.end = intervals[i].end;
            }
        }
        
        v.push_back(temp);
        return v;
    }
};
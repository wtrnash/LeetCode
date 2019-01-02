/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1:

输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]
示例 2:

输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出: [[1,2],[3,10],[12,16]]
解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。

*/

//解答：为空则直接插入返回；如果插入的结束比列表中最早的开始还要早，则先插入，再把后续的全部复制，返回；插入的开始比列表最晚的结束都要晚，则先复制列表，再最后插入；
//然后处理插入的在列表中间的情况，先比较和当前区间是否重合，即是否结束比其开始要晚且开始比其结束要早，如果重合，则更新要插入的区间；如果此时要插入的区间的结束比
//当前区间的开始要早，则直接插入，结束循环，后续直接将列表复制过去即可；如果不重合，要插入的区间的结束时间也不比当前区间的开始早，则把当前区间插入，以此类推即可
/*
 * Definition for an interval.
 */
#include <vector>
using namespace std;
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i = 0;
        int n = intervals.size();
        if(n == 0)  //处理空
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        vector<Interval> result;
        if(newInterval.end < intervals[0].start)    //处理最小的情况
        {
            result.push_back(newInterval);
            result.insert(result.end(), intervals.begin(), intervals.end());
            return result;
        }
        else if(newInterval.start > intervals[n - 1].end)   //处理最大的情况
        {
            result.assign(intervals.begin(), intervals.end());
            result.push_back(newInterval);
            return result;
        }
            
        while(i < n)
        {
            if(newInterval.end >= intervals[i].start && newInterval.start <= intervals[i].end)  //重合则更新当前插入的元素
            {
                newInterval.start = newInterval.start < intervals[i].start?newInterval.start:intervals[i].start;
                newInterval.end = newInterval.end < intervals[i].end?intervals[i].end:newInterval.end;
            }
            else if(newInterval.end < intervals[i].start)   //比当前区间小则插入后跳出循环
            {
                result.push_back(newInterval);
                break;
            }
            else
            {
                result.push_back(intervals[i]);
            }
             i++;
        }
        
        if(i == n)
            result.push_back(newInterval);
        while(i < n)
            result.push_back(intervals[i++]);   //插入剩下的区间
        
        return result;
    }
};
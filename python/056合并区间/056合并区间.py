"""
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
"""

# 解答：先按开始前后进行升序排序。然后每个区间和后一个区间进行比较，如果当前区间的结束时间大于等于后一个区间的开始时间，再选取两个里面结束时间晚的，进行合并
# 如果当前区间的结束时间小于后一个区间的开始时间，说明不重叠，则把当前区间压入新的数组。循环结束后压入最后一个区间
# Definition for an interval.
import copy
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        result = []
        if len(intervals) == 0:
            return result
        
        intervals.sort(key=lambda i: i.start)
        temp = Interval(intervals[0].start, intervals[0].end)
        for i in range(1, len(intervals)):
            if temp.end >= intervals[i].start:
                temp.end = max(temp.end, intervals[i].end)
            else:
                result.append(copy.copy(temp))
                temp.start = intervals[i].start
                temp.end = intervals[i].end
        
        result.append(copy.copy(temp))
        return result
        
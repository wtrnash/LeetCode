"""
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1:

输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]
示例 2:

输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出: [[1,2],[3,10],[12,16]]
解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。

"""

# 解答：遍历每个区间，如果重叠，则合并；否则，如果还没压入列表且要插入的结束比当前的开始小，则压入列表

# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        result = []
        if len(intervals) == 0:
            result.append(newInterval)
            return result
        
        isPush = False
        for i in range(len(intervals)):
            if newInterval.start <= intervals[i].end and intervals[i].start <= newInterval.end:
                newInterval.start = min(newInterval.start, intervals[i].start)
                newInterval.end = max(newInterval.end, intervals[i].end)
            else:
                if not isPush and newInterval.end < intervals[i].start:
                    result.append(newInterval)
                    isPush = True
                result.append(intervals[i])
        
        if not isPush:
            result.append(newInterval)
            
        return result
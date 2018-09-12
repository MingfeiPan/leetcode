# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if not intervals:
            return []
        
        intervals = sorted(intervals, key = lambda interval : interval.start)
        
        ret = []
        for i in range(0, len(intervals)):
            temp = intervals[i]
            if i == 0:
                ret.append(temp)
            else:
                if temp.start <= ret[-1].end:
                    ret[-1].end = max(ret[-1].end, temp.end)
                else:
                    ret.append(temp)
                    
        return ret
                
                
            

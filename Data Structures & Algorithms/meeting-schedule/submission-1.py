"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        sorted_intervals = sorted(intervals, key = lambda x: x.start)
        n = len(intervals)
        
        for i in range(n - 1):
            end_i_before = sorted_intervals[i].end
            start_i_after = sorted_intervals[i + 1].start
            if end_i_before > start_i_after:
                return False
        return True

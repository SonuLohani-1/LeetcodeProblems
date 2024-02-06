class Solution:
    # custom binary search just to find the index where the lower bound is just greater than or equal to newInterval's upper bound
    def custom_binary_I(self, intervals: list[list[int]], newInterval: list[int]) -> int:
        l, r = 0, len(intervals)
        while l <= r :
            mid = (l + r)/2
            if intervals[mid][0] == newInterval[0]:
                return mid
            elif intervals[mid][0] >


    # custom binary search just to find the index where the upper bound is just smaller than or equal to newInterval's upper bound

    def insert(self, intervals: list[list[int]], newInterval: list[int]) -> list[list[int]]:

        
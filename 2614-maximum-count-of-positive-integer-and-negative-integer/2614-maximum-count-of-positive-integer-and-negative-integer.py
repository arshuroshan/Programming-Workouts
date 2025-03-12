from bisect import bisect_left, bisect_right

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        neg_count = bisect_left(nums, 0)
        
        pos_count = len(nums) - bisect_right(nums, 0)

        return max(neg_count, pos_count)
from functools import reduce
from operator import xor

class Solution:
    def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
        mod = 10**9 + 7
        
        def apply_query(nums, l, r, k, v):
            for i in range(l, r + 1, k):
                nums[i] = (nums[i] * v) % mod
            return nums
        
        for l, r, k, v in queries:
            nums = apply_query(nums, l, r, k, v)
        
        return reduce(xor, nums)
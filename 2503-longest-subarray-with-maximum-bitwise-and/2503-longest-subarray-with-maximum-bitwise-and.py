class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        m = max(nums)
        r = c = 0
        for v in nums:
            if v == m:
                c += 1
                r = max(r, c)
            else:
                c = 0
        return r

class Solution:
    def maxSum(self, nums: List[int]) -> int:
        m = max(nums)
        if m <= 0:
            return m
        a = 0
        v = set()
        for n in nums:
            if n < 0 or n in v:
                continue
            a += n
            v.add(n)
        return a

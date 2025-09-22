class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        d = {}
        for x in nums:
            d[x] = d.get(x, 0) + 1
        m = max(d.values())
        return sum(v for v in d.values() if v == m)

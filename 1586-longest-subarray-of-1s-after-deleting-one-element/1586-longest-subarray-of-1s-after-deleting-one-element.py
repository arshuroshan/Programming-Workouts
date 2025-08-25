class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = [0]*(n+1), [0]*(n+1)
        for i in range(1, n+1):
            if nums[i-1]:
                l[i] = l[i-1] + 1
        for i in range(n-1, -1, -1):
            if nums[i]:
                r[i] = r[i+1] + 1
        return max(l[i] + r[i+1] for i in range(n))

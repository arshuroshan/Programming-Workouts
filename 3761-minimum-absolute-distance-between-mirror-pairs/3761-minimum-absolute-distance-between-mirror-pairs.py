class Solution:
    def minMirrorPairDistance(self, nums: List[int]) -> int:
        def rev(n):
            return int(str(n)[::-1])

        last_seen = {}
        best = float('inf')

        for i in range(len(nums)):
            val = nums[i]
            if val in last_seen:
                best = min(best, i - last_seen[val])
            last_seen[rev(val)] = i

        return -1 if best == float('inf') else best
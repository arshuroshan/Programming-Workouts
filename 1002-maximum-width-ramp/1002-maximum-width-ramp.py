class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        min_index = float('inf')
        ans = 0
        for j in sorted(range(len(nums)), key=lambda x: nums[x]):
            ans = max(ans, j - min_index)
            min_index = min(min_index, j)
        return ans
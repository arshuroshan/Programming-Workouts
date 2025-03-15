from bisect import bisect_left

class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        def can_select(x: int) -> bool:
            count = 0
            prev = -2
            for i, val in enumerate(nums):
                if val <= x and i > prev + 1:
                    count += 1
                    prev = i
                    if count >= k:
                        return True
            return count >= k

        left, right = min(nums), max(nums)
        while left < right:
            mid = (left + right) // 2
            if can_select(mid):
                right = mid
            else:
                left = mid + 1
        return left
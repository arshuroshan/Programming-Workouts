class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        left, right = 1, max(candies)
        while left < right:
            mid = (left + right + 1) // 2
            total = sum(x // mid for x in candies)

            if total >= k:
                left = mid
            else:
                right = mid - 1
        if sum(x // left for x in candies) >= k:
            return left
        else:
            return 0
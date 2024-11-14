class Solution:
    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        def canDistribute(maxPerStore):
            stores_needed = 0
            for quantity in quantities:
                stores_needed += (quantity + maxPerStore - 1) // maxPerStore
            return stores_needed <= n

        left, right = 1, max(quantities)

        while left < right:
            mid = (left + right) // 2
            if canDistribute(mid):
                right = mid
            else:
                left = mid + 1

        return left
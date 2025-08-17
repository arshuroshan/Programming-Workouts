class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        from functools import lru_cache
        @lru_cache(None)
        def f(i: int) -> float:
            if i >= k:
                return i <= n
            if i == k - 1:
                return min(n - k + 1, maxPts) / maxPts
            return f(i + 1) + (f(i + 1) - f(i + maxPts + 1)) / maxPts
        return f(0)

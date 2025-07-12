class Solution:
    def earliestAndLatest(self, n: int, firstPlayer: int, secondPlayer: int) -> List[int]:
        @functools.lru_cache(None)
        def f(l: int, r: int, k: int) -> List[int]:
            if l == r:
                return [1, 1]
            if l > r:
                return f(r, l, k)
            mn, mx = float('inf'), float('-inf')
            for i in range(1, l + 1):
                for j in range(l - i + 1, r - i + 1):
                    if not l + r - k // 2 <= i + j <= (k + 1) // 2:
                        continue
                    a, b = f(i, j, (k + 1) // 2)
                    mn = min(mn, a + 1)
                    mx = max(mx, b + 1)
            return [mn, mx]
        return f(firstPlayer, n - secondPlayer + 1, n)

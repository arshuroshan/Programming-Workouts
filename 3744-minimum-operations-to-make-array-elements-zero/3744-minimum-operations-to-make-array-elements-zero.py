class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        def g(x: int) -> int:
            r, p, i = 0, 1, 1
            while p <= x:
                c = min(p * 4 - 1, x) - p + 1
                r += c * i
                i += 1
                p *= 4
            return r
        a = 0
        for l, r in queries:
            s = g(r) - g(l - 1)
            m = g(r) - g(r - 1)
            a += max((s + 1) // 2, m)
        return a

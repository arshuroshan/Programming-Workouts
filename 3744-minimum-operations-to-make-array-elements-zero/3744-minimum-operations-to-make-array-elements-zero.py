class Solution:
    def minOperations(self, queries: List[List[int]]) -> int:
        def g(x: int) -> int:
            t = 0
            p = 1
            i = 1
            while p <= x:
                c = min(p * 4 - 1, x) - p + 1
                t += c * i
                i += 1
                p *= 4
            return t

        res = 0
        for l, r in queries:
            s = g(r) - g(l - 1)
            m = g(r) - g(r - 1)
            res += max((s + 1) // 2, m)
        return res

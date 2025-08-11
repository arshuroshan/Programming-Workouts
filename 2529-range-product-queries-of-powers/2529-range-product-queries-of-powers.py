class Solution:
    def productQueries(self, n: int, queries: List[List[int]]) -> List[int]:
        p = []
        while n:
            t = n & -n
            p.append(t)
            n -= t
        m = 10**9 + 7
        res = []
        for l, r in queries:
            v = 1
            for i in range(l, r + 1):
                v = v * p[i] % m
            res.append(v)
        return res

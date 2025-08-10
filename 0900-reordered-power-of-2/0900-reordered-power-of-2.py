class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        def cnt(x):
            r = [0] * 10
            while x:
                x, d = divmod(x, 10)
                r[d] += 1
            return r
        t, i = cnt(n), 1
        while i <= 10**9:
            if cnt(i) == t:
                return True
            i <<= 1
        return False

class Solution:
    def nextBeautifulNumber(self, n: int) -> int:
        i = n + 1
        while True:
            t, c = i, [0] * 10
            while t:
                t, d = divmod(t, 10)
                c[d] += 1
            if all(v == 0 or k == v for k, v in enumerate(c)):
                return i
            i += 1
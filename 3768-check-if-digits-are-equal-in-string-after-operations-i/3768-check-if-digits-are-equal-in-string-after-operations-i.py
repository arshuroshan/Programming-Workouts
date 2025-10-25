class Solution:
    def hasSameDigits(self, s: str) -> bool:
        a = [int(x) for x in s]
        for k in range(len(a) - 1, 1, -1):
            for i in range(k):
                a[i] = (a[i] + a[i + 1]) % 10
        return a[0] == a[1]
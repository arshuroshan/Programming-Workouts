class Solution:
    def peopleAwareOfSecret(self, n: int, delay: int, forget: int) -> int:
        mod = 10**9 + 7
        f = [0] * (n + forget + 1)
        f[1] = 1
        for i in range(1, n + 1):
            for j in range(i + delay, min(i + forget, n + 1)):
                f[j] = (f[j] + f[i]) % mod
        return sum(f[n - forget + 1 : n + 1]) % mod

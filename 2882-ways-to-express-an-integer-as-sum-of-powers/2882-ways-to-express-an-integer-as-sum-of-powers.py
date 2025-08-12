class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        m = 10**9 + 7
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            p = pow(i, x)
            for j in range(n + 1):
                dp[i][j] = dp[i - 1][j]
                if p <= j:
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % m
        return dp[n][n]

class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        mod = 10**9 + 7
        dp = [0] * (high + 1)
        dp[0] = 1
        
        for i in range(1, high + 1):
            if i >= zero:
                dp[i] = (dp[i] + dp[i - zero]) % mod
            if i >= one:
                dp[i] = (dp[i] + dp[i - one]) % mod
        
        return sum(dp[i] for i in range(low, high + 1)) % mod
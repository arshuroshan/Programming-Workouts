from bisect import bisect_left

class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        n = len(days)
        valid_durations = [1, 7, 30]
        dp = [float('inf')] * (n + 1)
        dp[-1] = 0
        
        for i in range(n-1, -1, -1):
            for cost, duration in zip(costs, valid_durations):
                next_day = bisect_left(days, days[i] + duration)
                dp[i] = min(dp[i], cost + dp[next_day])
        
        return dp[0]
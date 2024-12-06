class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if not prices:
            return 0
        
        n = len(prices)
        if k >= n // 2:
            return sum(max(prices[i + 1] - prices[i], 0) for i in range(n - 1))
        
        profits = [[0] * (k + 1) for _ in range(n)]
        
        for t in range(1, k + 1):
            maxDiff = -prices[0]
            for i in range(1, n):
                profits[i][t] = max(profits[i - 1][t], prices[i] + maxDiff)
                maxDiff = max(maxDiff, profits[i][t - 1] - prices[i])
        
        return profits[-1][-1]
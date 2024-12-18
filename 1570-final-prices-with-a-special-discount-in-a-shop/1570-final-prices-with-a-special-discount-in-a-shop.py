class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        result = prices[:]
        discount = [0] * n
        
        for i in range(n):
            for j in range(i + 1, n):
                if prices[j] <= prices[i]:
                    discount[i] = prices[j]
                    break
        
        for i in range(n):
            result[i] -= discount[i]
        
        return result
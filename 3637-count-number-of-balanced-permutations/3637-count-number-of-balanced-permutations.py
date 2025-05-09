from math import comb
from collections import Counter

class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        nums = list(map(int, num))
        total_sum = sum(nums)
        if total_sum % 2 != 0:
            return 0
        
        target = total_sum // 2
        n = len(nums)
        half = n // 2
        mod = 10**9 + 7
        digit_counts = Counter(nums)
        
        memo = {}
        
        def dp(digit, remaining_sum, left_remaining, right_remaining):
            if digit > 9:
                return 1 if (remaining_sum == 0 and left_remaining == 0 and right_remaining == 0) else 0
            
            key = (digit, remaining_sum, left_remaining, right_remaining)
            if key in memo:
                return memo[key]
            
            total = 0
            max_take = min(digit_counts[digit], left_remaining)
            
            for take in range(0, max_take + 1):
                leave = digit_counts[digit] - take
                if leave < 0 or leave > right_remaining:
                    continue
                if take * digit > remaining_sum:
                    continue
                
                ways = comb(left_remaining, take) * comb(right_remaining, leave)
                next_sum = remaining_sum - take * digit
                next_left = left_remaining - take
                next_right = right_remaining - leave
                
                total = (total + ways * dp(digit + 1, next_sum, next_left, next_right)) % mod
            
            memo[key] = total
            return total
        
        return dp(0, target, half, (n + 1) // 2)
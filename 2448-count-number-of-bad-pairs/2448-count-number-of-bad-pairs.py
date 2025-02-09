from collections import Counter

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        total_pairs = n * (n - 1) // 2
        
        freq = Counter()
        good_pairs = 0
        for i, x in enumerate(nums):
            key = x - i
            good_pairs += freq[key]
            freq[key] += 1 
        
        return total_pairs - good_pairs
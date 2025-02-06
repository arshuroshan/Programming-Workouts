from itertools import combinations
from collections import defaultdict

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        cnt = defaultdict(int)
        for a, b in combinations(nums, 2):
            cnt[a * b] += 1
        return sum(v * (v - 1) // 2 for v in cnt.values()) << 3
from typing import List
from collections import defaultdict

class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        extended_len = 2 * n
        
        dist = [extended_len] * extended_len

        last_seen = {}
        for i in range(extended_len):
            val = nums[i % n]
            if val in last_seen:
                dist[i] = i - last_seen[val]
            last_seen[val] = i

        next_seen = {}
        for i in range(extended_len - 1, -1, -1):
            val = nums[i % n]
            if val in next_seen:
                dist[i] = min(dist[i], next_seen[val] - i)
            next_seen[val] = i

        for i in range(n):
            dist[i] = min(dist[i], dist[i + n])

        result = []
        for q in queries:
            if dist[q] >= n:
                result.append(-1)
            else:
                result.append(dist[q])

        return result
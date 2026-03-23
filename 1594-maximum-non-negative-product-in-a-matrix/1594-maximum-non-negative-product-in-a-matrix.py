from math import inf
from typing import List

class Solution:
    def maxProductPath(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        min_dp = [[0] * cols for _ in range(rows)]
        max_dp = [[0] * cols for _ in range(rows)]

        min_dp[0][0] = grid[0][0]
        max_dp[0][0] = grid[0][0]

        for r in range(rows):
            for c in range(cols):
                if r == 0 and c == 0:
                    continue

                val = grid[r][c]
                candidates = []

                if r > 0:
                    candidates.append(min_dp[r - 1][c] * val)
                    candidates.append(max_dp[r - 1][c] * val)

                if c > 0:
                    candidates.append(min_dp[r][c - 1] * val)
                    candidates.append(max_dp[r][c - 1] * val)

                min_dp[r][c] = min(candidates)
                max_dp[r][c] = max(candidates)

        result = max_dp[rows - 1][cols - 1]
        MOD = 10**9 + 7

        return -1 if result < 0 else result % MOD
from functools import cache
from typing import List

class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        dirs = (1, 1, -1, -1, 1)

        @cache
        def dfs(i: int, j: int, k: int, c: int) -> int:
            x, y = i + dirs[k], j + dirs[k + 1]
            target = 2 if grid[i][j] == 1 else 2 - grid[i][j]
            if not (0 <= x < m) or not (0 <= y < n) or grid[x][y] != target:
                return 0
            r = dfs(x, y, k, c)
            if c > 0:
                r = max(r, dfs(x, y, (k + 1) % 4, 0))
            return 1 + r

        ans = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    for k in range(4):
                        ans = max(ans, dfs(i, j, k, 1) + 1)
        return ans

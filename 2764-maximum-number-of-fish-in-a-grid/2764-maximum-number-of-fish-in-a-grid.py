from collections import deque
from typing import List

class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        def bfs(i: int, j: int) -> int:
            queue = deque([(i, j)])
            total_fish = grid[i][j]
            grid[i][j] = 0
            while queue:
                x, y = queue.popleft()
                for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] > 0:
                        total_fish += grid[nx][ny]
                        grid[nx][ny] = 0
                        queue.append((nx, ny))
            return total_fish

        m, n = len(grid), len(grid[0])
        max_fish = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] > 0:
                    max_fish = max(max_fish, bfs(i, j))
        return max_fish
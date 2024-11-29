from heapq import heappop, heappush
from itertools import pairwise
from math import inf
from typing import List

class Solution:
    def minimumTime(self, grid: List[List[int]]) -> int:
        if grid[0][1] > 1 and grid[1][0] > 1:
            return -1
        
        m, n = len(grid), len(grid[0])
        dist = [[inf] * n for _ in range(m)]
        dist[0][0] = 0
        q = [(0, 0, 0)]
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        while q:
            t, i, j = heappop(q)
            if i == m - 1 and j == n - 1:
                return t
            
            for di, dj in directions:
                x, y = i + di, j + dj
                if 0 <= x < m and 0 <= y < n:
                    nt = t + 1
                    if nt < grid[x][y]:
                        nt = grid[x][y] + (grid[x][y] - nt) % 2
                    if nt < dist[x][y]:
                        dist[x][y] = nt
                        heappush(q, (nt, x, y))
        
        return -1

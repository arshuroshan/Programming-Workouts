from collections import deque

class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        q = deque([(0, 0, 0)])
        vis = set()
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while q:
            i, j, k = q.popleft()
            if i == m - 1 and j == n - 1:
                return k
            if (i, j) in vis:
                continue
            vis.add((i, j))

            for dx, dy in dirs:
                x, y = i + dx, j + dy
                if 0 <= x < m and 0 <= y < n:
                    if grid[x][y] == 0 and (x, y) not in vis:
                        q.appendleft((x, y, k))
                    elif grid[x][y] == 1 and (x, y) not in vis:
                        q.append((x, y, k + 1))
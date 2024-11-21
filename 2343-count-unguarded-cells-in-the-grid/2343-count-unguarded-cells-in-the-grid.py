class Solution:
    def countUnguarded(
        self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]
    ) -> int:
        grid = [[0] * n for _ in range(m)]
        
        for x, y in guards:
            grid[x][y] = 2
        for x, y in walls:
            grid[x][y] = 2
        
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        def mark_visible_cells(x, y, dx, dy):
            while 0 <= x < m and 0 <= y < n and grid[x][y] < 2:
                grid[x][y] = 1
                x += dx
                y += dy
        
        for x, y in guards:
            for dx, dy in directions:
                mark_visible_cells(x + dx, y + dy, dx, dy)
        
        return sum(cell == 0 for row in grid for cell in row)
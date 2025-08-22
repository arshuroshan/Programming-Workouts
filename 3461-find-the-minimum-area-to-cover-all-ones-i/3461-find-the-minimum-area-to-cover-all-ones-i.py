class Solution:
    def minimumArea(self, grid: List[List[int]]) -> int:
        a, b, c, d = inf, inf, -inf, -inf
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    a = min(a, i)
                    b = min(b, j)
                    c = max(c, i)
                    d = max(d, j)
        return (c - a + 1) * (d - b + 1)

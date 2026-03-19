class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])

        x_count = [[0] * (n + 1) for _ in range(m + 1)]
        y_count = [[0] * (n + 1) for _ in range(m + 1)]

        ans = 0

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                x_count[i][j] = x_count[i - 1][j] + x_count[i][j - 1] - x_count[i - 1][j - 1]
                y_count[i][j] = y_count[i - 1][j] + y_count[i][j - 1] - y_count[i - 1][j - 1]

                if grid[i - 1][j - 1] == 'X':
                    x_count[i][j] += 1
                elif grid[i - 1][j - 1] == 'Y':
                    y_count[i][j] += 1

                if x_count[i][j] > 0 and x_count[i][j] == y_count[i][j]:
                    ans += 1

        return ans
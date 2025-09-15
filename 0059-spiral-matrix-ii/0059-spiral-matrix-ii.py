class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        res = [[0] * n for _ in range(n)]
        d = (0, 1, 0, -1, 0)
        i = j = k = 0
        for v in range(1, n * n + 1):
            res[i][j] = v
            x, y = i + d[k], j + d[k + 1]
            if x < 0 or x >= n or y < 0 or y >= n or res[x][y]:
                k = (k + 1) % 4
            i, j = i + d[k], j + d[k + 1]
        return res

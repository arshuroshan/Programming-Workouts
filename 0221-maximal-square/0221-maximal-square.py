class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m, n = len(matrix), len(matrix[0])
        prev = [0] * (n + 1)
        mx = 0
        for i in range(m):
            curr = [0] * (n + 1)
            for j in range(n):
                if matrix[i][j] == '1':
                    curr[j + 1] = min(prev[j + 1], curr[j], prev[j]) + 1
                    mx = max(mx, curr[j + 1])
            prev = curr
        return mx * mx
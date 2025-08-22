class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        g = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if mat[i][j]:
                    g[i][j] = 1 if j == 0 else g[i][j-1] + 1
        res = 0
        for i in range(m):
            for j in range(n):
                v = float('inf')
                for k in range(i, -1, -1):
                    v = min(v, g[k][j])
                    res += v
        return res

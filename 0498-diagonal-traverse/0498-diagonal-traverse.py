class Solution:
    def findDiagonalOrder(self, mat: list[list[int]]) -> list[int]:
        m, n = len(mat), len(mat[0])
        res = []
        for k in range(m + n - 1):
            diag = []
            i = 0 if k < n else k - n + 1
            j = k if k < n else n - 1
            while i < m and j >= 0:
                diag.append(mat[i][j])
                i += 1
                j -= 1
            if k % 2 == 0:
                diag.reverse()
            res.extend(diag)
        return res

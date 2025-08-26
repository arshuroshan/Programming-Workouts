class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        res = d = 0
        for a, b in dimensions:
            s = a * a + b * b
            if s > d:
                d, res = s, a * b
            elif s == d:
                res = max(res, a * b)
        return res

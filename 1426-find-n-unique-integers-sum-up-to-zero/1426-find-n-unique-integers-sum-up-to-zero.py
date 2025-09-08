class Solution:
    def sumZero(self, n: int) -> List[int]:
        res = [i + 1 for i in range(n >> 1)] + [-(i + 1) for i in range(n >> 1)]
        if n & 1:
            res.append(0)
        return res

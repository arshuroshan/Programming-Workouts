class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        d1, d2 = abs(x - z), abs(y - z)
        return 0 if d1 == d2 else 1 if d1 < d2 else 2

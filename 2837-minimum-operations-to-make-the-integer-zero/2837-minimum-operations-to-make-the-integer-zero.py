from itertools import count

class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for k in count(1):
            v = num1 - k * num2
            if v < 0:
                return -1
            if v.bit_count() <= k <= v:
                return k

class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
        guess = x
        while guess * guess > x:
            guess = (guess + x // guess) // 2
        return guess
class Solution:
    def minEnd(self, n: int, x: int) -> int:
        n -= 1
        ans = x
        for i in range(31):
            if (x & (1 << i)) == 0:
                ans |= (n & 1) << i
                n >>= 1
        ans |= (n << 31)
        return ans
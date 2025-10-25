class Solution:
    def totalMoney(self, n: int) -> int:
        w, d = divmod(n, 7)
        a = (28 + 28 + 7 * (w - 1)) * w // 2
        b = (w + 1 + w + d) * d // 2
        return a + b
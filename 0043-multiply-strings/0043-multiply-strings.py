class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0":
            return "0"
        m, n = len(num1), len(num2)
        res = [0] * (m + n)
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                res[i + j + 1] += int(num1[i]) * int(num2[j])
        for i in range(m + n - 1, 0, -1):
            res[i - 1] += res[i] // 10
            res[i] %= 10
        return "".join(map(str, res if res[0] else res[1:]))

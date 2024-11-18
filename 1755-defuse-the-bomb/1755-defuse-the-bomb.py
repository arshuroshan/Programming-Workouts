class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        if k == 0:
            return [0] * n

        extended = code + code
        ans = [0] * n

        prefix = [0] * (2 * n + 1)
        for i in range(1, 2 * n + 1):
            prefix[i] = prefix[i - 1] + extended[i - 1]

        for i in range(n):
            if k > 0:
                ans[i] = prefix[i + k + 1] - prefix[i + 1]
            else:
                ans[i] = prefix[i + n] - prefix[i + n + k]

        return ans
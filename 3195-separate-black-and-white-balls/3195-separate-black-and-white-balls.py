class Solution:
    def minimumSteps(self, s: str) -> int:
        n = len(s)
        ans = 0
        ones_count = 0
        for i in range(n):
            if s[i] == '1':
                ones_count += 1
            else:
                ans += ones_count
        return ans
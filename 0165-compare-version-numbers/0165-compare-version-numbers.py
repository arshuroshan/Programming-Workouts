class Solution:
    def compareVersion(self, v1: str, v2: str) -> int:
        i = j = 0
        m, n = len(v1), len(v2)
        while i < m or j < n:
            a = b = 0
            while i < m and v1[i] != '.':
                a = a * 10 + int(v1[i])
                i += 1
            while j < n and v2[j] != '.':
                b = b * 10 + int(v2[j])
                j += 1
            if a != b:
                return 1 if a > b else -1
            i += 1
            j += 1
        return 0
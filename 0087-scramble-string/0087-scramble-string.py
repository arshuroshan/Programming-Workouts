class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        @cache
        def f(a, b, c):
            if c == 1:
                return s1[a] == s2[b]
            for d in range(1, c):
                if f(a, b, d) and f(a + d, b + d, c - d):
                    return True
                if f(a + d, b, c - d) and f(a, b + c - d, d):
                    return True
            return False
        return f(0, 0, len(s1))
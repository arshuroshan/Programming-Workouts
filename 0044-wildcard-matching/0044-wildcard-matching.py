class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        from functools import cache
        @cache
        def f(i, j):
            if i == len(s):
                return j == len(p) or (j < len(p) and p[j] == "*" and f(i, j + 1))
            if j == len(p):
                return False
            if p[j] == "*":
                return f(i + 1, j) or f(i, j + 1)
            return (p[j] == "?" or s[i] == p[j]) and f(i + 1, j + 1)
        return f(0, 0)

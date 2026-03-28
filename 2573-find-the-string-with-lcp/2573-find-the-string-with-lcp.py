from typing import List
from string import ascii_lowercase

class Solution:
    def findTheString(self, lcp: List[List[int]]) -> str:
        n = len(lcp)
        chars = [''] * n
        ptr = 0

        for ch in ascii_lowercase:
            while ptr < n and chars[ptr] != '':
                ptr += 1

            if ptr == n:
                break

            for k in range(ptr, n):
                if lcp[ptr][k] > 0:
                    chars[k] = ch

        if any(ch == '' for ch in chars):
            return ""

        for x in range(n - 1, -1, -1):
            for y in range(n - 1, -1, -1):
                if chars[x] == chars[y]:
                    expected = 1 if (x == n - 1 or y == n - 1) else lcp[x + 1][y + 1] + 1
                    if lcp[x][y] != expected:
                        return ""
                else:
                    if lcp[x][y] != 0:
                        return ""

        return ''.join(chars)
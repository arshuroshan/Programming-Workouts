import collections

class Solution:
    def __init__(self):
        self.LIMIT = 10**6 + 1

    def smallestPalindrome(self, s: str, k: int) -> str:
        freq = collections.Counter(s)
        odd = [c for c, v in freq.items() if v & 1]
        if len(odd) > 1:
            return ""

        half = [0] * 26
        mid = ""

        for c in freq:
            idx = ord(c) - 97
            half[idx] = freq[c] // 2
            if freq[c] & 1:
                mid = c

        if self.arrangements(half) < k:
            return ""

        left = []
        remain = sum(half)

        while remain:
            for i in range(26):
                if half[i] == 0:
                    continue
                half[i] -= 1
                ways = self.arrangements(half)
                if ways >= k:
                    left.append(chr(i + 97))
                    remain -= 1
                    break
                k -= ways
                half[i] += 1

        return "".join(left) + mid + "".join(reversed(left))

    def arrangements(self, half):
        slots = sum(half)
        ans = 1

        for x in half:
            if x:
                ans *= self.choose(slots, x)
                if ans >= self.LIMIT:
                    return self.LIMIT
                slots -= x

        return ans

    def choose(self, n, r):
        r = min(r, n - r)
        val = 1
        for i in range(1, r + 1):
            val = val * (n - r + i) // i
            if val >= self.LIMIT:
                return self.LIMIT
        return val
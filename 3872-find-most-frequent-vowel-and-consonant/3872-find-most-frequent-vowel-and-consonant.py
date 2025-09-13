class Solution:
    def maxFreqSum(self, s: str) -> int:
        d = Counter(s)
        x = max((d[c] for c in d if c in "aeiou"), default=0)
        y = max((d[c] for c in d if c not in "aeiou"), default=0)
        return x + y
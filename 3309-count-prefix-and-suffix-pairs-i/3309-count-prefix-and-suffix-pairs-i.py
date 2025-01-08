class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        return sum(1 for i, s in enumerate(words) for t in words[i + 1:] if t.startswith(s) and t.endswith(s))
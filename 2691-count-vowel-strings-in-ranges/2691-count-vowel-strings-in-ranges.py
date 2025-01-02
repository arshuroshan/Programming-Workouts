class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = set("aeiou")
        prefix_sum = [0] * (len(words) + 1)

        for i, word in enumerate(words):
            prefix_sum[i + 1] = prefix_sum[i] + (1 if word[0] in vowels and word[-1] in vowels else 0)

        return [prefix_sum[r + 1] - prefix_sum[l] for l, r in queries]
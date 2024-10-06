class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        words1 = sentence1.split()
        words2 = sentence2.split()

        if len(words1) < len(words2):
            words1, words2 = words2, words1

        left = 0
        right = 0
        n = len(words2)
        m = len(words1)

        while left < n and words1[left] == words2[left]:
            left += 1

        while right < n and words1[m - 1 - right] == words2[n - 1 - right]:
            right += 1

        return left + right >= n
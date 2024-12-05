class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        prev_row = list(range(n + 1))

        for i in range(1, m + 1):
            curr_row = [i] * (n + 1)
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    curr_row[j] = prev_row[j - 1]
                else:
                    curr_row[j] = min(prev_row[j], curr_row[j - 1], prev_row[j - 1]) + 1
            prev_row = curr_row

        return prev_row[n]
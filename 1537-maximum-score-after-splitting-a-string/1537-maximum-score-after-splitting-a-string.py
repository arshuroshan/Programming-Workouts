class Solution:
    def maxScore(self, s: str) -> int:
        left_score = 1 if s[0] == '0' else 0
        right_score = s[1:].count('1')
        max_score = left_score + right_score

        for i in range(1, len(s) - 1):
            if s[i] == '0':
                left_score += 1
            else:
                right_score -= 1
            max_score = max(max_score, left_score + right_score)

        return max_score

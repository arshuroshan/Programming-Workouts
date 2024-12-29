class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        m, n = len(target), len(words[0])
        mod = 10**9 + 7

        cnt = [[0] * 26 for _ in range(n)]
        for word in words:
            for j, char in enumerate(word):
                cnt[j][ord(char) - ord('a')] += 1
        
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        
        for j in range(n + 1):
            dp[0][j] = 1
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):

                dp[i][j] = dp[i][j - 1]

                char_index = ord(target[i - 1]) - ord('a')
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * cnt[j - 1][char_index]) % mod

        return dp[m][n]
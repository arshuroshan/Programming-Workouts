class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int mod = 1e9 + 7;
        
        vector<vector<int>> comb(n, vector<int>(16, 0));
        for (int i = 0; i < n; ++i) {
            comb[i][0] = 1;
            if (i > 0) {
                for (int j = 1; j < 16; ++j) {
                    comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
                }
            }
        }

        vector<vector<long long>> dp(maxValue + 1, vector<long long>(16, 0));
        for (int v = 1; v <= maxValue; ++v) {
            dp[v][1] = 1;
        }

        for (int len = 1; len < 15; ++len) {
            for (int v = 1; v <= maxValue; ++v) {
                if (dp[v][len] == 0) continue;
                for (int m = 2; v * m <= maxValue; ++m) {
                    dp[v * m][len + 1] = (dp[v * m][len + 1] + dp[v][len]) % mod;
                }
            }
        }

        long long result = 0;
        for (int v = 1; v <= maxValue; ++v) {
            for (int len = 1; len < 16; ++len) {
                result = (result + dp[v][len] * comb[n-1][len-1]) % mod;
            }
        }

        return result;
    }
};
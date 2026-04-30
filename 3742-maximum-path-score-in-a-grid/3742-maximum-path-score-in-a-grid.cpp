class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int neg = -1e9;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, neg)));
        dp[0][0][k] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int t = 0; t <= k; ++t) {
                    if (dp[i][j][t] == neg) continue;

                    if (i + 1 < m) {
                        int nt = t - (grid[i + 1][j] > 0);
                        if (nt >= 0) {
                            dp[i + 1][j][nt] = max(dp[i + 1][j][nt], dp[i][j][t] + grid[i + 1][j]);
                        }
                    }

                    if (j + 1 < n) {
                        int nt = t - (grid[i][j + 1] > 0);
                        if (nt >= 0) {
                            dp[i][j + 1][nt] = max(dp[i][j + 1][nt], dp[i][j][t] + grid[i][j + 1]);
                        }
                    }
                }
            }
        }

        int ans = neg;
        for (int t = 0; t <= k; ++t) ans = max(ans, dp[m - 1][n - 1][t]);
        return ans < 0 ? -1 : ans;
    }
};
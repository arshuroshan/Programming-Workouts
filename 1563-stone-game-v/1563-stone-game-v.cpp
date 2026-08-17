class Solution {
public:
    int stoneGameV(vector<int>& a) {
        int n = a.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; ++i)
            pre[i + 1] = pre[i] + a[i];

        vector<vector<int>> dp(n, vector<int>(n));

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                int best = 0;

                for (int k = i; k < j; ++k) {
                    int left = pre[k + 1] - pre[i];
                    int right = pre[j + 1] - pre[k + 1];

                    if (left < right) {
                        best = max(best, left + dp[i][k]);
                    } else if (left > right) {
                        best = max(best, right + dp[k + 1][j]);
                    } else {
                        best = max(best, left + max(dp[i][k], dp[k + 1][j]));
                    }
                }

                dp[i][j] = best;
            }
        }

        return dp[0][n - 1];
    }
};
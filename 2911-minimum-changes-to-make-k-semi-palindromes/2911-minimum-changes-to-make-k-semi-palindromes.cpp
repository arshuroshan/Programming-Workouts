
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d < len; ++d) {
                if (len % d != 0) continue;

                for (int i = 0; i + len <= n; ++i) {
                    int changes = 0;

                    for (int r = 0; r < d; ++r) {
                        int left = i + r;
                        int right = i + r + (len / d - 1) * d;

                        while (left < right) {
                            changes += (s[left] != s[right]);
                            left += d;
                            right -= d;
                        }
                    }

                    cost[i][i + len - 1] = min(
                        cost[i][i + len - 1], changes
                    );
                }
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for (int parts = 1; parts <= k; ++parts) {
            for (int end = parts * 2; end <= n; ++end) {
                for (int start = (parts - 1) * 2; start <= end - 2; ++start) {
                    if (dp[parts - 1][start] == INF) continue;

                    dp[parts][end] = min(
                        dp[parts][end],
                        dp[parts - 1][start] + cost[start][end - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};

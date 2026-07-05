class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int mod = 1000000007;

        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        dp[n - 1][n - 1] = {0, 1};

        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1)) continue;

                int best = -1, ways = 0;
                vector<pair<int, int>> nxt = {{i + 1, j}, {i, j + 1}, {i + 1, j + 1}};

                for (auto [x, y] : nxt) {
                    if (x >= n || y >= n || dp[x][y].first == -1) continue;

                    if (dp[x][y].first > best) {
                        best = dp[x][y].first;
                        ways = dp[x][y].second;
                    } else if (dp[x][y].first == best) {
                        ways = (ways + dp[x][y].second) % mod;
                    }
                }

                if (best != -1) {
                    if (isdigit(board[i][j])) best += board[i][j] - '0';
                    dp[i][j] = {best, ways};
                }
            }
        }

        if (dp[0][0].first == -1) return {0, 0};
        return {dp[0][0].first, dp[0][0].second};
    }
};
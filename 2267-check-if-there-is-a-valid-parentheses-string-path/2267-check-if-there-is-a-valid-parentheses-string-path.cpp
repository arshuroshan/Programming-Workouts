class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int len = m + n - 1;

        if (len % 2 == 1 || grid[0][0] != '(' || grid[m - 1][n - 1] != ')')
            return false;

        vector<vector<unordered_set<int>>> dp(
            m, vector<unordered_set<int>>(n)
        );

        dp[0][0].insert(1);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0)
                    continue;

                int delta = grid[i][j] == '(' ? 1 : -1;
                int remaining = (m - 1 - i) + (n - 1 - j);

                if (i > 0) {
                    for (int balance : dp[i - 1][j]) {
                        int next = balance + delta;
                        if (next >= 0 && next <= remaining)
                            dp[i][j].insert(next);
                    }
                }

                if (j > 0) {
                    for (int balance : dp[i][j - 1]) {
                        int next = balance + delta;
                        if (next >= 0 && next <= remaining)
                            dp[i][j].insert(next);
                    }
                }
            }
        }

        return dp[m - 1][n - 1].count(0);
    }
};
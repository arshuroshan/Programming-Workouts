
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int limit = 1;
        for (const auto& row : grid) {
            for (int value : row) {
                while (limit <= value) {
                    limit *= 2;
                }
            }
        }

        vector<vector<unsigned char>> dp(cols, vector<unsigned char>(limit, 0));
        dp[0][grid[0][0]] = 1;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }

                vector<unsigned char> current(limit, 0);
                int value = grid[i][j];

                if (i > 0) {
                    for (int x = 0; x < limit; ++x) {
                        if (dp[j][x]) {
                            current[x ^ value] = 1;
                        }
                    }
                }

                if (j > 0) {
                    for (int x = 0; x < limit; ++x) {
                        if (dp[j - 1][x]) {
                            current[x ^ value] = 1;
                        }
                    }
                }

                dp[j] = move(current);
            }
        }

        for (int x = 0; x < limit; ++x) {
            if (dp[cols - 1][x]) {
                return x;
            }
        }

        return -1;
    }
};

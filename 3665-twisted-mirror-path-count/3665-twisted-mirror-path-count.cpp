
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        auto vornadexil = grid;

        vector<int> right(n, 0), down(n, 0);
        right[0] = down[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int a = j > 0 ? right[j - 1] : 0;
                int b = i > 0 ? down[j] : 0;

                if (i == 0 && j == 0)
                    continue;

                if (grid[i][j] == 1) {
                    right[j] = b;
                    down[j] = a;
                } else {
                    int ways = (a + b) % MOD;
                    right[j] = ways;
                    down[j] = ways;
                }
            }
        }

        return right[n - 1];
    }
};

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k %= total;

        vector<int> vals;
        vals.reserve(total);

        for (auto &row : grid) {
            for (int x : row) {
                vals.push_back(x);
            }
        }

        rotate(vals.rbegin(), vals.rbegin() + k, vals.rend());

        vector<vector<int>> res(m, vector<int>(n));
        int idx = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = vals[idx++];
            }
        }

        return res;
    }
};
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        for (int layer = 0; layer < min(m, n) / 2; ++layer) {
            vector<pair<int,int>> pos;

            for (int c = layer; c < n - layer - 1; ++c)
                pos.push_back({layer, c});

            for (int r = layer; r < m - layer - 1; ++r)
                pos.push_back({r, n - layer - 1});

            for (int c = n - layer - 1; c > layer; --c)
                pos.push_back({m - layer - 1, c});

            for (int r = m - layer - 1; r > layer; --r)
                pos.push_back({r, layer});

            int len = pos.size();
            int shift = k % len;

            vector<int> vals(len);

            for (int i = 0; i < len; ++i) {
                auto [x, y] = pos[(i + shift) % len];
                vals[i] = grid[x][y];
            }

            for (int i = 0; i < len; ++i) {
                auto [x, y] = pos[i];
                grid[x][y] = vals[i];
            }
        }

        return grid;
    }
};
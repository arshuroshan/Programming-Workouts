class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vals;
        vals.reserve(grid.size() * grid[0].size());

        int r = grid[0][0] % x;

        for (auto& row : grid) {
            for (int v : row) {
                if (v % x != r) return -1;
                vals.push_back(v);
            }
        }

        nth_element(vals.begin(), vals.begin() + vals.size() / 2, vals.end());
        int median = vals[vals.size() / 2];

        int ops = 0;
        for (int v : vals) {
            ops += abs(v - median) / x;
        }

        return ops;
    }
};
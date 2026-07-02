class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size(), cols = grid[0].size();

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<int>> cost(rows, vector<int>(cols, INT_MAX));
        cost[0][0] = grid[0][0];
        pq.push({cost[0][0], 0, 0});

        vector<pair<int, int>> move = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.empty()) {
            auto [loss, r, c] = pq.top();
            pq.pop();

            if (loss != cost[r][c]) continue;

            for (auto [dr, dc] : move) {
                int nr = r + dr, nc = c + dc;

                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                int nextLoss = loss + grid[nr][nc];

                if (nextLoss < cost[nr][nc]) {
                    cost[nr][nc] = nextLoss;
                    pq.push({nextLoss, nr, nc});
                }
            }
        }

        return cost[rows - 1][cols - 1] < health;
    }
};
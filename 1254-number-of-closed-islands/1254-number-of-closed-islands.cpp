class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        auto bfs = [&](int r, int c) {
            queue<pair<int, int>> q;
            q.push({r, c});
            grid[r][c] = 1;

            bool closed = true;
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};

            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();

                if (x == 0 || y == 0 || x == m - 1 || y == n - 1)
                    closed = false;

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }

            return closed;
        };

        int count = 0;

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0 && bfs(i, j))
                    count++;
            }
        }

        return count;
    }
};
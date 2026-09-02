class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] || grid[n - 1][n - 1])
            return 0;

        vector<vector<int>> safe(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    safe[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    safe[nr][nc] == INT_MAX) {
                    safe[nr][nc] = safe[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        auto possible = [&](int limit) {
            if (safe[0][0] < limit || safe[n - 1][n - 1] < limit)
                return false;

            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int, int>> bfs;

            bfs.push({0, 0});
            visited[0][0] = true;

            while (!bfs.empty()) {
                auto [r, c] = bfs.front();
                bfs.pop();

                if (r == n - 1 && c == n - 1)
                    return true;

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                        !visited[nr][nc] && safe[nr][nc] >= limit) {
                        visited[nr][nc] = true;
                        bfs.push({nr, nc});
                    }
                }
            }

            return false;
        };

        int low = 0;
        int high = n * n;
        int answer = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return answer;
    }
};
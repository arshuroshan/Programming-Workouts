class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sx, sy, lights = 0;
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (classroom[i][j] == 'L') {
                    id[i][j] = lights++;
                }
            }
        }

        if (lights == 0)
            return 0;

        int fullMask = (1 << lights) - 1;

        vector<vector<vector<int>>> seen(
            m, vector<vector<int>>(n, vector<int>(1 << lights, -1))
        );

        queue<array<int, 4>> q;
        q.push({sx, sy, energy, fullMask});
        seen[sx][sy][fullMask] = energy;

        int steps = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                if (mask == 0)
                    return steps;

                if (e == 0)
                    continue;

                for (int k = 0; k < 4; ++k) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    int ne = e - 1;
                    if (classroom[nr][nc] == 'R')
                        ne = energy;

                    int nmask = mask;

                    if (classroom[nr][nc] == 'L')
                        nmask &= ~(1 << id[nr][nc]);

                    if (seen[nr][nc][nmask] >= ne)
                        continue;

                    seen[nr][nc][nmask] = ne;
                    q.push({nr, nc, ne, nmask});
                }
            }

            ++steps;
        }

        return -1;
    }
};
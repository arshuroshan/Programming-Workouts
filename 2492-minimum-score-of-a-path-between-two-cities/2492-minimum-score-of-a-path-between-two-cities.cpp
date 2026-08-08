class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (const auto& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        vector<bool> visited(n + 1);
        queue<int> q;
        q.push(1);
        visited[1] = true;

        int ans = INT_MAX;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto& [v, weight] : graph[u]) {
                ans = min(ans, weight);

                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};
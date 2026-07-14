class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        constexpr int MOD = 1000000007;
        int n = static_cast<int>(edges.size()) + 1;

        vector<vector<int>> graph(n + 1);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, int>> nodes;
        vector<bool> visited(n + 1, false);

        nodes.push({1, 0});
        visited[1] = true;

        int maximumDepth = 0;

        while (!nodes.empty()) {
            auto [node, depth] = nodes.front();
            nodes.pop();

            maximumDepth = max(maximumDepth, depth);

            for (int neighbour : graph[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    nodes.push({neighbour, depth + 1});
                }
            }
        }

        return modularPower(2, maximumDepth - 1, MOD);
    }

private:
    int modularPower(long long base, int exponent, int mod) {
        long long result = 1;

        while (exponent > 0) {
            if (exponent & 1) {
                result = result * base % mod;
            }

            base = base * base % mod;
            exponent >>= 1;
        }

        return static_cast<int>(result);
    }
};
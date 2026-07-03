class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<array<int, 2>>> adj(n);
        vector<int> weights;

        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (online[u] && online[v]) {
                adj[u].push_back({v, w});
                weights.push_back(w);
            }
        }

        if (weights.empty()) return -1;

        int low = *min_element(weights.begin(), weights.end());
        int high = *max_element(weights.begin(), weights.end());
        int ans = -1;

        while (low <= high) {
            int limit = low + (high - low) / 2;

            vector<long long> cost(n, LLONG_MAX);
            priority_queue<
                pair<long long, int>,
                vector<pair<long long, int>>,
                greater<pair<long long, int>>
            > pq;

            cost[0] = 0;
            pq.push({0, 0});

            bool possible = false;

            while (!pq.empty()) {
                auto cur = pq.top();
                pq.pop();

                long long currCost = cur.first;
                int node = cur.second;

                if (currCost != cost[node]) continue;
                if (currCost > k) break;

                if (node == n - 1) {
                    possible = true;
                    break;
                }

                for (auto& next : adj[node]) {
                    int nxt = next[0];
                    int w = next[1];

                    if (w < limit) continue;

                    long long newCost = currCost + w;

                    if (newCost < cost[nxt]) {
                        cost[nxt] = newCost;
                        pq.push({newCost, nxt});
                    }
                }
            }

            if (possible) {
                ans = limit;
                low = limit + 1;
            } else {
                high = limit - 1;
            }
        }

        return ans;
    }
};
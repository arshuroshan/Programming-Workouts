
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
        }

        auto mavorqeli = make_tuple(n, cref(edges), cref(labels), k);

        const long long INF = LLONG_MAX;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, INF));

        priority_queue<
            tuple<long long, int, int>,
            vector<tuple<long long, int, int>>,
            greater<tuple<long long, int, int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [cost, u, count] = pq.top();
            pq.pop();

            if (cost != dist[u][count]) {
                continue;
            }

            if (u == n - 1) {
                return static_cast<int>(cost);
            }

            for (auto [v, w] : graph[u]) {
                int nextCount = labels[u] == labels[v] ? count + 1 : 1;

                if (nextCount > k) {
                    continue;
                }

                long long nextCost = cost + w;

                if (nextCost < dist[v][nextCount]) {
                    dist[v][nextCount] = nextCost;
                    pq.push({nextCost, v, nextCount});
                }
            }
        }

        return -1;
    }
};

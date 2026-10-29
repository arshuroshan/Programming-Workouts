
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        const int LOG = 17;
        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n), tin(n), tout(n), parent(n, -1);
        vector<int> bit(n + 2), mask(n);
        int timer = 0;

        auto add = [&](int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        };

        auto get = [&](int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        };

        vector<int> order;
        order.reserve(n);
        order.push_back(0);
        parent[0] = 0;

        for (int i = 0; i < (int)order.size(); ++i) {
            int u = order[i];
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                order.push_back(v);
            }
        }

        for (int u : order) {
            up[0][u] = parent[u];
            for (int j = 1; j < LOG; ++j)
                up[j][u] = up[j - 1][up[j - 1][u]];
        }

        vector<int> it(n);
        vector<int> st = {0};

        while (!st.empty()) {
            int u = st.back();

            if (it[u] == 0)
                tin[u] = ++timer;

            if (it[u] == (int)adj[u].size()) {
                tout[u] = timer;
                st.pop_back();
                continue;
            }

            int v = adj[u][it[u]++];
            if (v != parent[u])
                st.push_back(v);
        }

        for (int u = 0; u < n; ++u) {
            mask[u] = 1 << (s[u] - 'a');
            add(tin[u], mask[u]);
            add(tout[u] + 1, mask[u]);
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; ++j)
                if (diff & (1 << j))
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; --j) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return parent[u];
        };

        vector<bool> ans;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                add(tin[u], delta);
                add(tout[u] + 1, delta);

                mask[u] = newMask;
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);
                int x = get(tin[u]) ^ get(tin[v]) ^ mask[w];

                ans.push_back((x & (x - 1)) == 0);
            }
        }

        return ans;
    }
};

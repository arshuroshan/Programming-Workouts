
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> last(26, -1);
        vector<int> previous(n, -1);
        vector<int> order;
        vector<pair<int, bool>> st;

        st.push_back({0, false});

        while (!st.empty()) {
            auto [u, done] = st.back();
            st.pop_back();

            int c = s[u] - 'a';

            if (done) {
                last[c] = previous[u];
                continue;
            }

            previous[u] = last[c];

            if (last[c] != -1) {
                newParent[u] = last[c];
            }

            last[c] = u;
            order.push_back(u);

            st.push_back({u, true});

            for (int i = (int)adj[u].size() - 1; i >= 0; --i) {
                st.push_back({adj[u][i], false});
            }
        }

        vector<int> ans(n, 1);

        for (int i = n - 1; i > 0; --i) {
            int u = order[i];
            ans[newParent[u]] += ans[u];
        }

        return ans;
    }
};

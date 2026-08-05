class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> dir(n), und(n);
        for (auto &e : invocations) {
            dir[e[0]].push_back(e[1]);
            und[e[0]].push_back(e[1]);
            und[e[1]].push_back(e[0]);
        }

        vector<int> bad(n, 0), seen(n, 0);
        queue<int> q;

        bad[k] = 1;
        q.push(k);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : dir[u]) {
                if (!bad[v]) {
                    bad[v] = 1;
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (bad[i] || seen[i]) continue;
            queue<int> cur;
            cur.push(i);
            seen[i] = 1;
            while (!cur.empty()) {
                int u = cur.front();
                cur.pop();
                bad[u] = 0;
                for (int v : und[u]) {
                    if (!seen[v]) {
                        seen[v] = 1;
                        bad[v] = 0;
                        cur.push(v);
                    }
                }
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!bad[i]) res.push_back(i);
        }
        return res;
    }
};
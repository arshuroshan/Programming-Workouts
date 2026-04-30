class Solution {
public:
    int n, B;
    vector<vector<int>> g;
    vector<int> present, future;

    vector<array<int,2>> dfs(int u) {
        vector<array<int,2>> dp(B + 1, {0, 0});

        for (int v : g[u]) {
            vector<array<int,2>> child = dfs(v);
            vector<array<int,2>> temp = dp;

            for (int j = 0; j <= B; j++) {
                for (int k = 0; k + j <= B; k++) {
                    for (int s = 0; s < 2; s++) {
                        temp[j + k][s] = max(temp[j + k][s], dp[j][s] + child[k][s]);
                    }
                }
            }
            dp.swap(temp);
        }

        vector<array<int,2>> res(B + 1, {0, 0});
        int gain = future[u - 1];

        for (int j = 0; j <= B; j++) {
            for (int s = 0; s < 2; s++) {
                int cost = present[u - 1] / (s + 1);
                res[j][s] = dp[j][0];
                if (j >= cost) {
                    res[j][s] = max(res[j][s], dp[j - cost][1] + gain - cost);
                }
            }
        }

        return res;
    }

    int maxProfit(int n_, vector<int>& p, vector<int>& f, vector<vector<int>>& h, int budget) {
        n = n_;
        B = budget;
        present = p;
        future = f;
        g.assign(n + 1, {});

        for (auto& e : h) {
            g[e[0]].push_back(e[1]);
        }

        return dfs(1)[B][0];
    }
};
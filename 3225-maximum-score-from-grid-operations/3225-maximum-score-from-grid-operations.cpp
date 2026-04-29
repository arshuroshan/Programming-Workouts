class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<long long>> pref(n, vector<long long>(n + 1, 0));

        for (int c = 0; c < n; ++c)
            for (int r = 0; r < n; ++r)
                pref[c][r + 1] = pref[c][r] + grid[r][c];

        vector<long long> pick(n + 1, 0), skip(n + 1, 0);

        for (int c = 1; c < n; ++c) {
            vector<long long> np(n + 1, 0), ns(n + 1, 0);

            for (int cur = 0; cur <= n; ++cur) {
                long long bestPick = 0, bestSkip = 0;

                for (int prv = 0; prv <= n; ++prv) {
                    if (cur > prv) {
                        long long val = pref[c - 1][cur] - pref[c - 1][prv];
                        bestPick = max(bestPick, skip[prv] + val);
                        bestSkip = max(bestSkip, skip[prv] + val);
                    } else {
                        long long val = pref[c][prv] - pref[c][cur];
                        bestPick = max(bestPick, pick[prv] + val);
                        bestSkip = max(bestSkip, pick[prv]);
                    }
                }

                np[cur] = bestPick;
                ns[cur] = bestSkip;
            }

            pick.swap(np);
            skip.swap(ns);
        }

        return *max_element(pick.begin(), pick.end());
    }
};
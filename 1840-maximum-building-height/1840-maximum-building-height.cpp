class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        vector<vector<int>> v;
        for (auto &x : restrictions) {
            if (v.empty() || v.back()[0] != x[0]) {
                v.push_back(x);
            } else {
                v.back()[1] = min(v.back()[1], x[1]);
            }
        }

        int size = v.size();

        for (int i = 1; i < size; i++) {
            int dist = v[i][0] - v[i - 1][0];
            v[i][1] = min(v[i][1], v[i - 1][1] + dist);
        }

        for (int i = size - 2; i >= 0; i--) {
            int dist = v[i + 1][0] - v[i][0];
            v[i][1] = min(v[i][1], v[i + 1][1] + dist);
        }

        int best = 0;

        for (int i = 1; i < size; i++) {
            int leftPos = v[i - 1][0];
            int rightPos = v[i][0];
            int leftHeight = v[i - 1][1];
            int rightHeight = v[i][1];

            int peak = (leftHeight + rightHeight + rightPos - leftPos) / 2;
            best = max(best, peak);
        }

        return best;
    }
};
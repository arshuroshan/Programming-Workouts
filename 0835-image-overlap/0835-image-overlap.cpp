class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> a, b;

        for (int i = 0; i < img1.size(); ++i) {
            for (int j = 0; j < img1.size(); ++j) {
                if (img1[i][j]) a.push_back({i, j});
                if (img2[i][j]) b.push_back({i, j});
            }
        }

        unordered_map<int, int> freq;
        int n = img1.size();
        int res = 0;

        for (auto [x1, y1] : a) {
            for (auto [x2, y2] : b) {
                int dx = x1 - x2;
                int dy = y1 - y2;
                int key = (dx + n) * (2 * n + 1) + (dy + n);
                res = max(res, ++freq[key]);
            }
        }

        return res;
    }
};
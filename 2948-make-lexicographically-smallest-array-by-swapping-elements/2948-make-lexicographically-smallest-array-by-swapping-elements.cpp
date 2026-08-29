class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> a;

        for (int i = 0; i < n; ++i)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<int> ans = nums;
        int l = 0;

        while (l < n) {
            int r = l;

            while (r + 1 < n && a[r + 1].first - a[r].first <= limit)
                ++r;

            vector<int> values;
            vector<int> positions;

            for (int i = l; i <= r; ++i) {
                values.push_back(a[i].first);
                positions.push_back(a[i].second);
            }

            sort(positions.begin(), positions.end());

            for (int i = 0; i < values.size(); ++i)
                ans[positions[i]] = values[i];

            l = r + 1;
        }

        return ans;
    }
};
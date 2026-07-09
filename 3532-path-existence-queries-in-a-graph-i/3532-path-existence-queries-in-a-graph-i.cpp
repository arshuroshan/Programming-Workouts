class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> prefix(n, 0);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
        }

        vector<bool> result;
        result.reserve(queries.size());

        for (auto &q : queries) {
            result.emplace_back(prefix[q[0]] == prefix[q[1]]);
        }

        return result;
    }
};
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 1), idx(n);

        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return arr[a] < arr[b];
        });

        for (int i : idx) {
            for (int j = i - 1; j >= max(0, i - d); --j) {
                if (arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], dp[j] + 1);
            }

            for (int j = i + 1; j <= min(n - 1, i + d); ++j) {
                if (arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
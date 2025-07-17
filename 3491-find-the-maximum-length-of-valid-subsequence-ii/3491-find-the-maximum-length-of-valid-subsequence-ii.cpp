class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k));
        int res = 0;
        for (int a : nums) {
            int x = a % k;
            for (int j = 0; j < k; j++) {
                int y = (j - x + k) % k;
                dp[x][y] = dp[y][x] + 1;
                res = max(res, dp[x][y]);
            }
        }
        return res;
    }
};

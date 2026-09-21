class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k), dp(k);

        for (auto v : nums) {
            vector<long long> next(k);

            next[v % k]++;

            for (int i = 0; i < k; i++) {
                int rem = (long long)i * v % k;
                next[rem] += dp[i];
            }

            for (int i = 0; i < k; i++) {
                res[i] += next[i];
            }

            dp = move(next);
        }

        return res;
    }
};
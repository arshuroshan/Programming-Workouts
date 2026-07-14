class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        constexpr int MOD = 1'000'000'007;
        int limit = *max_element(nums.begin(), nums.end());

        vector<vector<int>> dp(limit + 1, vector<int>(limit + 1));
        dp[0][0] = 1;

        for (int x : nums) {
            vector<vector<int>> next(limit + 1, vector<int>(limit + 1));

            for (int a = 0; a <= limit; ++a) {
                for (int b = 0; b <= limit; ++b) {
                    if (dp[a][b] == 0) continue;

                    int ways = dp[a][b];
                    int ga = gcd(a, x);
                    int gb = gcd(b, x);

                    next[a][b] = (next[a][b] + ways) % MOD;
                    next[ga][b] = (next[ga][b] + ways) % MOD;
                    next[a][gb] = (next[a][gb] + ways) % MOD;
                }
            }

            dp = move(next);
        }

        int answer = 0;

        for (int g = 0; g <= limit; ++g) {
            answer = (answer + dp[g][g]) % MOD;
        }

        return (answer - 1 + MOD) % MOD;
    }
};
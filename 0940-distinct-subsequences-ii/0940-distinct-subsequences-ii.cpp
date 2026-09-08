class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;
        vector<long long> dp(26);
        long long total = 0;

        for (char c : s) {
            int idx = c - 'a';
            long long next = (total + 1) % MOD;

            total = (total - dp[idx] + next + MOD) % MOD;
            dp[idx] = next;
        }

        return (int)total;
    }
};
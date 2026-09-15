class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1);

        for (int center = 0; center < n; ++center) {
            for (int type = 0; type < 2; ++type) {
                int l = center;
                int r = center + type;

                while (l >= 0 && r < n && s[l] == s[r]) {
                    if (r - l + 1 >= k) {
                        dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    }
                    --l;
                    ++r;
                }
            }

            dp[center + 1] = max(dp[center + 1], dp[center]);
        }

        return dp[n];
    }
};
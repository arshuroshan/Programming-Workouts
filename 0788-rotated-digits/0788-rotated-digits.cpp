class Solution {
public:
    int dp[11][2][2];

    int dfs(string &s, int pos, bool tight, bool diff) {
        if (pos == s.size()) return diff;
        if (dp[pos][tight][diff] != -1) return dp[pos][tight][diff];

        int limit = tight ? s[pos] - '0' : 9;
        int res = 0;

        for (int d = 0; d <= limit; d++) {
            if (d == 3 || d == 4 || d == 7) continue;

            bool ndiff = diff || (d == 2 || d == 5 || d == 6 || d == 9);
            res += dfs(s, pos + 1, tight && (d == limit), ndiff);
        }

        return dp[pos][tight][diff] = res;
    }

    int rotatedDigits(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, 1, 0);
    }
};
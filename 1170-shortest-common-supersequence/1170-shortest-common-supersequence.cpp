class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string result;
        int i = m, j = n;
        while (i > 0 || j > 0) {
            if (i == 0) {
                result += str2[--j];
            } else if (j == 0) {
                result += str1[--i];
            } else if (str1[i - 1] == str2[j - 1]) {
                result += str1[--i];
                --j;
            } else if (dp[i][j] == dp[i - 1][j]) {
                result += str1[--i];
            } else {
                result += str2[--j];
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
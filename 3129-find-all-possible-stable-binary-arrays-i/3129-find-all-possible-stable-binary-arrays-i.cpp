class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        static constexpr int MOD = 1'000'000'007;

        vector<vector<long long>> endZero(
            zero + 1, vector<long long>(one + 1)
        );
        vector<vector<long long>> endOne(
            zero + 1, vector<long long>(one + 1)
        );

        for (int i = 1; i <= min(zero, limit); ++i) {
            endZero[i][0] = 1;
        }

        for (int j = 1; j <= min(one, limit); ++j) {
            endOne[0][j] = 1;
        }

        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                endZero[i][j] =
                    (endZero[i - 1][j] + endOne[i - 1][j]) % MOD;

                if (i > limit) {
                    endZero[i][j] =
                        (endZero[i][j] - endOne[i - limit - 1][j] + MOD) % MOD;
                }

                endOne[i][j] =
                    (endZero[i][j - 1] + endOne[i][j - 1]) % MOD;

                if (j > limit) {
                    endOne[i][j] =
                        (endOne[i][j] - endZero[i][j - limit - 1] + MOD) % MOD;
                }
            }
        }

        return static_cast<int>(
            (endZero[zero][one] + endOne[zero][one]) % MOD
        );
    }
};
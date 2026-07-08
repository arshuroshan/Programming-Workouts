class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1000000007;
        int n = s.size();

        vector<long long> ten(n + 1, 1), val(n + 1);
        vector<int> digitSum(n + 1), nonZero(n + 1);

        for (int i = 1; i <= n; ++i) {
            ten[i] = ten[i - 1] * 10 % MOD;
        }

        for (int i = 0; i < n; ++i) {
            int d = s[i] - '0';
            digitSum[i + 1] = digitSum[i] + d;
            nonZero[i + 1] = nonZero[i] + (d != 0);
            val[i + 1] = val[i];

            if (d != 0) {
                val[i + 1] = (val[i + 1] * 10 + d) % MOD;
            }
        }

        vector<int> res;
        res.reserve(queries.size());

        for (const auto& q : queries) {
            int l = q[0], r = q[1];

            int sum = digitSum[r + 1] - digitSum[l];
            int len = nonZero[r + 1] - nonZero[l];

            long long num = val[r + 1] - val[l] * ten[len] % MOD;
            if (num < 0) num += MOD;

            res.push_back(num * sum % MOD);
        }

        return res;
    }
};
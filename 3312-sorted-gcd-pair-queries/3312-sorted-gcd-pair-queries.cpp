class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = *max_element(nums.begin(), nums.end());

        vector<int> freq(n + 1), mu(n + 1), primes;
        vector<bool> composite(n + 1);

        for (int x : nums) {
            ++freq[x];
        }

        mu[1] = 1;

        for (int i = 2; i <= n; ++i) {
            if (!composite[i]) {
                primes.push_back(i);
                mu[i] = -1;
            }

            for (int p : primes) {
                if (i * p > n) break;

                composite[i * p] = true;

                if (i % p == 0) {
                    mu[i * p] = 0;
                    break;
                }

                mu[i * p] = -mu[i];
            }
        }

        vector<long long> divisible(n + 1);

        for (int d = 1; d <= n; ++d) {
            for (int multiple = d; multiple <= n; multiple += d) {
                divisible[d] += freq[multiple];
            }
        }

        vector<long long> prefix(n + 1);

        for (int g = 1; g <= n; ++g) {
            long long exact = 0;

            for (int k = 1; g * k <= n; ++k) {
                long long count = divisible[g * k];
                exact += 1LL * mu[k] * count * (count - 1) / 2;
            }

            prefix[g] = prefix[g - 1] + exact;
        }

        vector<int> result;
        result.reserve(queries.size());

        for (long long query : queries) {
            result.push_back(
                upper_bound(prefix.begin(), prefix.end(), query) - prefix.begin()
            );
        }

        return result;
    }
};
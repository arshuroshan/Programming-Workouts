class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        using ll = long long;
        int n = coins.size();

        auto count = [&](ll x) {
            ll total = 0;

            for (int mask = 1; mask < (1 << n); ++mask) {
                ll common = 1;

                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        common = lcm(common, (ll)coins[i]);
                        if (common > x)
                            break;
                    }
                }

                if (common > x)
                    continue;

                ll ways = x / common;

                if (__builtin_popcount(mask) % 2)
                    total += ways;
                else
                    total -= ways;
            }

            return total;
        };

        ll low = 1, high = 1e11;

        while (low < high) {
            ll mid = low + (high - low) / 2;

            if (count(mid) < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};
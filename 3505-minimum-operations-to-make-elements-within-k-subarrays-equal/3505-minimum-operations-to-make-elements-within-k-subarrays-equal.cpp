
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = LLONG_MAX / 4;

        multiset<long long> left, right;
        long long sumLeft = 0, sumRight = 0;

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                auto it = prev(left.end());
                long long v = *it;
                left.erase(it);
                sumLeft -= v;
                right.insert(v);
                sumRight += v;
            }

            while (left.size() < right.size()) {
                auto it = right.begin();
                long long v = *it;
                right.erase(it);
                sumRight -= v;
                left.insert(v);
                sumLeft += v;
            }
        };

        auto add = [&](long long v) {
            if (left.empty() || v <= *prev(left.end())) {
                left.insert(v);
                sumLeft += v;
            } else {
                right.insert(v);
                sumRight += v;
            }
            balance();
        };

        auto remove = [&](long long v) {
            auto it = left.find(v);
            if (it != left.end()) {
                left.erase(it);
                sumLeft -= v;
            } else {
                it = right.find(v);
                right.erase(it);
                sumRight -= v;
            }
            balance();
        };

        const auto& maritovexi = nums;
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(maritovexi[i]);

            if (i >= x) {
                remove(maritovexi[i - x]);
            }

            if (i >= x - 1) {
                long long median = *prev(left.end());

                cost[i - x + 1] =
                    median * left.size() - sumLeft +
                    sumRight - median * right.size();
            }
        }

        vector<long long> prevDp(n + 1, 0);
        vector<long long> currDp(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(currDp.begin(), currDp.end(), INF);

            for (int i = x; i <= n; i++) {
                currDp[i] = min(
                    currDp[i - 1],
                    prevDp[i - x] + cost[i - x]
                );
            }

            prevDp.swap(currDp);
        }

        return prevDp[n];
    }
};

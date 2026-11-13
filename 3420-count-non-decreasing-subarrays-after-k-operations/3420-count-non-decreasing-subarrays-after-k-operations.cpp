
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int right = n - 1;
        long long ans = 0, cost = 0;

        deque<pair<int, int>> dq;

        for (int left = n - 1; left >= 0; --left) {
            int value = nums[left];
            int count = 1;

            while (!dq.empty() && dq.back().first < value) {
                auto [v, c] = dq.back();
                dq.pop_back();

                cost += 1LL * (value - v) * c;
                count += c;
            }

            dq.push_back({value, count});

            while (cost > k) {
                auto [v, c] = dq.front();
                dq.pop_front();

                cost -= 1LL * (v - nums[right]);
                --right;

                if (c > 1) {
                    dq.push_front({v, c - 1});
                }
            }

            ans += right - left + 1;
        }

        return ans;
    }
};

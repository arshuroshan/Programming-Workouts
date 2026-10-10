class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long operations = 1LL * k1 + k2;
        vector<long long> diff;
        long long total = 0;
        int high = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            total += d;
            high = max(high, d);
        }

        if (total <= operations) return 0;

        int low = 0;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long required = 0;

            for (long long d : diff) {
                if (d > mid) required += d - mid;
            }

            if (required <= operations)
                high = mid;
            else
                low = mid + 1;
        }

        for (long long& d : diff) {
            if (d > low) {
                operations -= d - low;
                d = low;
            }
        }

        long long result = 0;

        for (long long d : diff) {
            if (operations > 0 && d == low) {
                d--;
                operations--;
            }
            result += d * d;
        }

        return result;
    }
};
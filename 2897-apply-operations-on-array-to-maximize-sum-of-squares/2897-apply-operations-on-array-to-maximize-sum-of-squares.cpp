
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1000000007;
        vector<int> freq(31, 0);

        for (int num : nums) {
            int bit = 0;
            while (num > 0) {
                freq[bit++] += num % 2;
                num /= 2;
            }
        }

        long long result = 0;

        for (int j = 0; j < k; j++) {
            long long value = 0;

            for (int bit = 30; bit >= 0; bit--) {
                if (freq[bit] > 0) {
                    value += (1LL << bit);
                    freq[bit]--;
                }
            }

            result = (result + value * value) % MOD;
        }

        return static_cast<int>(result);
    }
};

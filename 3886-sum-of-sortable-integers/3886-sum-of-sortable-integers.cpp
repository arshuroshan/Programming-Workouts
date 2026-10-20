
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMin(n + 1, INT_MAX);

        for (int i = n - 1; i >= 0; --i) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }

        auto valid = [&](int len) -> bool {
            int leftMax = INT_MIN;

            for (int l = 0; l < n; l += len) {
                int r = l + len;
                
                if (leftMax > rightMin[l])
                    return false;

                int changes = 0;

                for (int j = l + 1; j < r; ++j) {
                    if (nums[j] < nums[j - 1])
                        ++changes;
                }

                if (nums[r - 1] > nums[l])
                    ++changes;

                if (changes > 1)
                    return false;

                for (int j = l; j < r; ++j) {
                    leftMax = max(leftMax, nums[j]);
                }
            }

            return true;
        };

        int result = 0;

        for (int len = 1; len <= n; ++len) {
            if (n % len == 0 && valid(len)) {
                result += len;
            }
        }

        return result;
    }
};

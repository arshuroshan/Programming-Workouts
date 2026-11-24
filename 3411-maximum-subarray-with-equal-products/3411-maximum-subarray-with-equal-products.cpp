
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            long long lcmVal = 1;
            int gcdVal = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                product *= x;
                gcdVal = gcd(gcdVal, x);
                lcmVal = lcm(lcmVal, (long long)x);

                if (product == gcdVal * lcmVal) {
                    ans = max(ans, j - i + 1);
                }

                if (product > gcdVal * lcmVal) {
                    break;
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx = 0, ans = 0;
        int n = nums.size();
        for (int x : nums) {
            mx |= x;
        }
        
        for (int mask = 0; mask < (1 << n); ++mask) {
            int currentOr = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    currentOr |= nums[i];
                }
            }
            if (currentOr == mx) {
                ++ans;
            }
        }
        return ans;
    }
};
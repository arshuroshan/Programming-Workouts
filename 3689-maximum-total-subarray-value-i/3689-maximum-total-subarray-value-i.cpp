class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = nums[0], mx = nums[0];

        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
        }

        return (long long)(mx - mn) * k;
    }
};
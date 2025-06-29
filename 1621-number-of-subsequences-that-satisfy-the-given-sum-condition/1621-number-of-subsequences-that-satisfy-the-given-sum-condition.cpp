class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9 + 7, n = nums.size(), f[n + 1], ans = 0;
        f[0] = 1;
        for (int i = 1; i <= n; i++) f[i] = (f[i - 1] * 2) % mod;
        for (int i = 0; i < n && nums[i] * 2 <= target; i++) {
            int j = upper_bound(nums.begin() + i + 1, nums.end(), target - nums[i]) - nums.begin() - 1;
            ans = (ans + f[j - i]) % mod;
        }
        return ans;
    }
};

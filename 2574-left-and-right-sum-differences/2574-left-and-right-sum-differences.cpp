class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n + 1, 0), ans(n);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            int left = pref[i];
            int right = pref[n] - pref[i + 1];
            ans[i] = abs(left - right);
        }

        return ans;
    }
};
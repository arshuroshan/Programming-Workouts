class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n), pref(n);

        partial_sum(nums.begin(), nums.end(), pref.begin(),
            [](int a, int b) {
                return max(a, b);
            });

        int mn = INT_MAX;
        int nxt = 0;

        for (int i = n - 1; i >= 0; --i) {
            res[i] = (pref[i] > mn) ? nxt : pref[i];
            nxt = res[i];
            mn = min(mn, nums[i]);
        }

        return res;
    }
};
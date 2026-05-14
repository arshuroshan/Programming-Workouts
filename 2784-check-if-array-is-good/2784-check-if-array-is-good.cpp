class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        sort(nums.begin(), nums.end());

        if (nums.back() != n || nums[nums.size() - 2] != n) {
            return false;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] != i + 1) {
                return false;
            }
        }

        return true;
    }
};
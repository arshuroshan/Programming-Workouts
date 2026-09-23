class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        int left = 0;
        int current = 0;
        int longest = -1;

        for (int right = 0; right < nums.size(); ++right) {
            current += nums[right];

            while (left <= right && current > target) {
                current -= nums[left++];
            }

            if (current == target) {
                longest = max(longest, right - left + 1);
            }
        }

        return longest == -1 ? -1 : nums.size() - longest;
    }
};
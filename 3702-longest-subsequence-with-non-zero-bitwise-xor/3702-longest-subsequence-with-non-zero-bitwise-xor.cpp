class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int zeros = count(nums.begin(), nums.end(), 0);

        if (x != 0)
            return nums.size();

        return zeros == nums.size() ? 0 : nums.size() - 1;
    }
};
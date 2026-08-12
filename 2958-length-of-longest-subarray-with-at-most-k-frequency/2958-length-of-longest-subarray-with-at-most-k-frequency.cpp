class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, res = 0;

        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            if (freq[nums[right]] > k) {
                while (nums[left] != nums[right]) {
                    freq[nums[left]]--;
                    left++;
                }
                freq[nums[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};
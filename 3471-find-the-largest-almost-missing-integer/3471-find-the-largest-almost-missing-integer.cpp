class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == n)
            return *max_element(nums.begin(), nums.end());

        if (k == 1) {
            unordered_map<int, int> freq;
            for (int x : nums)
                freq[x]++;

            int ans = -1;
            for (auto [x, c] : freq)
                if (c == 1)
                    ans = max(ans, x);

            return ans;
        }

        int ans = -1;

        if (count(nums.begin() + 1, nums.end(), nums[0]) == 0)
            ans = nums[0];

        if (count(nums.begin(), nums.end() - 1, nums[n - 1]) == 0)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};
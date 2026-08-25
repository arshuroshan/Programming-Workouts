class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for (int x = k; ; x += k) {
            if (find(nums.begin(), nums.end(), x) == nums.end())
                return x;
        }
    }
};
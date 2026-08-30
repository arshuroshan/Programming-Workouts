class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minPos = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxPos = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minPos, maxPos);
        int right = max(minPos, maxPos);

        int removeLeft = right + 1;
        int removeRight = n - left;
        int removeBoth = left + 1 + n - right;

        return min({removeLeft, removeRight, removeBoth});
    }
};
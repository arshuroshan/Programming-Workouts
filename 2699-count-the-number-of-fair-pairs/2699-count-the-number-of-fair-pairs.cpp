class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countLessEqual(nums, upper) - countLessEqual(nums, lower - 1);
    }

private:
    long long countLessEqual(vector<int>& nums, int val) {
        long long count = 0;
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum <= val) {
                count += right - left;
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};
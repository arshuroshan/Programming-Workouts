class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            if (nums[low] <= nums[high]) {
                return nums[low];
            }

            int pivot = low + (high - low) / 2;

            if (nums[pivot] >= nums[low]) {
                low = pivot + 1;
            } else {
                high = pivot;
            }
        }

        return nums[low];
    }
};
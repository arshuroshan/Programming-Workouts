class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];
            int sum = 0;

            for (; value > 0; value /= 10)
                sum += value % 10;

            if (sum == i)
                return i;
        }

        return -1;
    }
};
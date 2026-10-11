
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int result = 0;
        int length = nums.size();

        for (int index = 0; index < length; index++) {
            if (length % (index + 1) != 0)
                continue;

            int value = nums[index];
            result += value * value;
        }

        return result;
    }
};

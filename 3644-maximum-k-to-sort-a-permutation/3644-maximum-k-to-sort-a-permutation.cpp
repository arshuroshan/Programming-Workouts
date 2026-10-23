
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int result = 0;
        bool found = false;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i)
                continue;

            if (!found) {
                result = nums[i];
                found = true;
            } else {
                result = result & nums[i];
            }
        }

        return found ? result : 0;
    }
};

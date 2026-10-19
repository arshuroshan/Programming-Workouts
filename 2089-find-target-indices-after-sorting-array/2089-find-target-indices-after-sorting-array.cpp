
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0, equal = 0;

        for (int num : nums) {
            if (num < target) smaller++;
            else if (num == target) equal++;
        }

        vector<int> result(equal);
        iota(result.begin(), result.end(), smaller);

        return result;
    }
};

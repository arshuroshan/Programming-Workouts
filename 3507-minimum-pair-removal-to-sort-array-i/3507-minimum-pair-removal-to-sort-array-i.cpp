class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (true) {
            bool sorted = true;

            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    sorted = false;
                    break;
                }
            }

            if (sorted) return operations;

            int index = 0;
            int bestSum = nums[0] + nums[1];

            for (int i = 1; i + 1 < nums.size(); i++) {
                int currentSum = nums[i] + nums[i + 1];

                if (currentSum < bestSum) {
                    bestSum = currentSum;
                    index = i;
                }
            }

            vector<int> next;

            for (int i = 0; i < nums.size(); i++) {
                if (i == index) {
                    next.push_back(bestSum);
                    i++;
                } else {
                    next.push_back(nums[i]);
                }
            }

            nums = next;
            operations++;
        }
    }
};
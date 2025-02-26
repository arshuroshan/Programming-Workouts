class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefixSum = 0;
        int maxPrefix = 0, minPrefix = 0;
        int maxAbsSum = 0;

        for (int& x : nums) {
            prefixSum += x;
            maxAbsSum = max({maxAbsSum, abs(prefixSum - minPrefix), abs(prefixSum - maxPrefix)});
            maxPrefix = max(maxPrefix, prefixSum);
            minPrefix = min(minPrefix, prefixSum);
        }

        return maxAbsSum;
    }
};
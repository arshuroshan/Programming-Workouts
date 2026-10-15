class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int result = 0;

        for (int start = 0; start < nums.size(); start++) {
            unordered_set<int> unique;

            for (int end = start; end < nums.size(); end++) {
                unique.insert(nums[end]);
                int count = unique.size();
                result += count * count;
            }
        }

        return result;
    }
};
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> numSet(nums.begin(), nums.end());
        int maxStreak = -1;
        
        for (int num : nums) {
            long long current = num;
            int streakLength = 0;

            while (numSet.find(current) != numSet.end()) {
                current *= current;
                ++streakLength;
            }
            
            if (streakLength > 1) {
                maxStreak = max(maxStreak, streakLength);
            }
        }
        
        return maxStreak;
    }
};
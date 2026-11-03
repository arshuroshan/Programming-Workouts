
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int target = *max_element(nums.begin(), nums.end());
        int moves = 0;

        for (int num : nums) {
            moves += target - num;
        }

        return moves;
    }
};

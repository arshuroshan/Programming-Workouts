class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pairXor;
        unordered_set<int> tripletXor;

        for (int x : nums) {
            for (int y : nums) {
                pairXor.insert(x ^ y);
            }
        }

        for (int value : pairXor) {
            for (int x : nums) {
                tripletXor.insert(value ^ x);
            }
        }

        return tripletXor.size();
    }
};
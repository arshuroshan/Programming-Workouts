class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n < 3)
            return n;

        int bits = 0;
        for (int x = n; x > 0; x >>= 1)
            ++bits;

        return 1 << bits;
    }
};
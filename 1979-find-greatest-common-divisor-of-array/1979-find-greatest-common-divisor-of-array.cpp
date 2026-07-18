class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];

        for (int x : nums) {
            if (x < mn) mn = x;
            if (x > mx) mx = x;
        }

        return std::gcd(mn, mx);
    }
};
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> vals;
        int largest = 0;

        for (int x : nums) {
            largest = max(largest, x);
            vals.push_back(__gcd(largest, x));
        }

        sort(vals.begin(), vals.end());

        long long res = 0;
        int l = 0, r = vals.size() - 1;

        while (l < r) {
            res += __gcd(vals[l], vals[r]);
            l++;
            r--;
        }

        return res;
    }
};
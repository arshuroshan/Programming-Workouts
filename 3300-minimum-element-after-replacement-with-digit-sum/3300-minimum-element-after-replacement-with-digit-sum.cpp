class Solution {
public:
    int minElement(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 100, [](int best, int n) {
            int sum = 0;
            string s = to_string(n);

            for (char c : s) {
                sum += c - '0';
            }

            return min(best, sum);
        });
    }
};
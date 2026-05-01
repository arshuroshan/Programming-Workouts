class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        
        long long curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += 1LL * i * nums[i];
        }
        
        long long res = curr;
        
        for (int i = n - 1; i > 0; --i) {
            curr = curr + total - 1LL * n * nums[i];
            res = max(res, curr);
        }
        
        return (int)res;
    }
};
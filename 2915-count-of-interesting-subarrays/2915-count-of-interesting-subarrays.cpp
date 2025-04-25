class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;
        
        long long interesting = 0;
        int current_sum = 0;
        
        for (int num : nums) {
            int val = (num % modulo == k) ? 1 : 0;
            current_sum = (current_sum + val) % modulo;
            
            int target = (current_sum - k + modulo) % modulo;
            
            interesting += prefix_counts[target];
            prefix_counts[current_sum]++;
        }
        
        return interesting;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index_map;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            if (index_map.find(complement) != index_map.end()) {
                return {index_map[complement], i};
            }
            
            index_map[nums[i]] = i;
        }
        
        return {};
    }
};
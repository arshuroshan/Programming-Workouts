#include <vector>
#include <map>

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        std::map<int, int> mergedMap;

        for (const auto& pair : nums1) {
            int id = pair[0];
            int value = pair[1];
            mergedMap[id] += value;
        }

        for (const auto& pair : nums2) {
            int id = pair[0];
            int value = pair[1];
            mergedMap[id] += value;
        }

        vector<vector<int>> ans;
        for (const auto& [id, value] : mergedMap) {
            ans.push_back({id, value});
        }

        return ans;
    }
};
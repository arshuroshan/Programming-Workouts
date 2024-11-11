class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currentPermutation;
        backtrack(nums, currentPermutation, ans);
        return ans;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& currentPermutation, vector<vector<int>>& ans) {
        if (currentPermutation.size() == nums.size()) {
            ans.push_back(currentPermutation);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (find(currentPermutation.begin(), currentPermutation.end(), nums[i]) != currentPermutation.end()) {
                continue;
            }
            currentPermutation.push_back(nums[i]);
            backtrack(nums, currentPermutation, ans);
            currentPermutation.pop_back();
        }
    }
};